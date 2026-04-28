/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:19:28 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/22 17:31:50 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// allocate the argv table
int	add_str(t_token **tokens, t_cmd *command)
{
	int		size;
	t_token	*current;

	size = 0;
	current = (*tokens);
	// as long as there are no pipe
	while (current && current->type != PIPE)
	{
		// increment if there are words
		if (current->type == WORD)
			size++;
		// and move forward
		current = current->next;
	}
	// allocate argv
	command->argv = malloc(sizeof(char *) * (size + 1));
	// check for malloc errors
	if (!command->argv)
		return (1);
	return (0);
}

// fill one command with a token
int	cmd_fill(t_token **tokens, t_cmd *command)
{
	int	i;

	i = 0;
	// allocate my argv table
	if (add_str(tokens, command))
		return (1);
	// loop over tokens as long as it doen't hit a pipe
	while ((*tokens) && (*tokens)->type != PIPE)
	{
		// if it's a word
		if ((*tokens)->type == WORD)
		{
			// copy it into argv
			command->argv[i] = ft_strdup((*tokens)->value);
			// check for malloc error
			if (!command->argv[i])
				return (1);
			// move to the next token
			(*tokens) = (*tokens)->next;
			// and argv[i]
			i++;
		}
		// if it's a redirection
		else if ((*tokens)->type != WORD)
		{
			// add it with the function
			if (append_redir(tokens, command))
				return (1); // malloc fail check
		}
	}
	// last argv is NULL
	command->argv[i] = NULL;
	// and next command too
	command->next = NULL;
	// sucessful fill
	return (0);
}

// my global creating commands function
t_cmd	*append_cmd(int *lst_ext, t_token **tokens, t_cmd *commands)
{
	t_cmd	*current_cmd;

	// check for empty first token
	if (!(*tokens))
		return (NULL);
	// loop over each token
	while ((*tokens))
	{
		// save a new command
		current_cmd = new_cmd();
		if (!current_cmd) // check for malloc errors
			return (malloc_err(lst_ext), free_commands(&commands), NULL);
		// fill the actual command + malloc error check
		if (cmd_fill(tokens, current_cmd))
			return (malloc_err(lst_ext), free_commands(&current_cmd),
				free_commands(&commands), NULL);
		// if there is a pipe skip the pipe token
		if ((*tokens) && (*tokens)->type == PIPE)
			(*tokens) = (*tokens)->next;
		// add the command to the linked list
		add_cmd(&commands, current_cmd);
	}
	// return my done commands
	return (commands);
}

// main parsing function
t_cmd	*parse(int *lst_ext, t_token **tokens)
{
	t_cmd	*commands;

	// init command
	commands = NULL;
	// check if there are syntax error
	if (syntax_check(*tokens))
	{
		*lst_ext = 2; // if so last exit is set to 2
		// still free my tokens and return nothing
		return (free_tokens(tokens), NULL);
	}
	// build my command linked list
	commands = append_cmd(lst_ext, tokens, commands);
	// check for any malloc fail
	if (*lst_ext == 1) // if there are any free my tokens and commands
		return (free_tokens(tokens), free_commands(&commands), NULL);
	// free my tokens after commands were build
	free_tokens(tokens);
	return (commands);
}
