/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:04:11 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/21 11:00:04 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_tokens(t_token **tokens)
{
	t_token *current;

	if (!tokens || !(*tokens))
		return ;
	while (*tokens)
	{
		current = (*tokens)->next;
		free((*tokens)->value);
		free(*tokens);
		*tokens = current;
	}
}

t_cmd *append_cmd(int *lst_ext, t_token *tokens, t_cmd *commands)
{
	commands = NULL;
	if (!(*tokens))
		return (NULL);
	// loop
}

t_cmd	*parse(int *lst_ext, t_token **tokens)
{
	t_cmd *commands;

	commands = NULL;
	if (syntax_check(*tokens))
	{
		*lst_ext = 2;
		return(free_tokens(tokens), NULL);
	}
	commands = append_cmd(*lst_ext, tokens, commands); // append_cmd
	if (*lst_ext == 1)
		return (free_tokens(tokens), NULL);
	free_tokens(tokens);
	return (commands);
}

///////////////////////////////////////////////////////////////

int	filling(t_token **tokens, t_cmd *command)
{
	int	i;

	i = 0;
	while (*tokens && (*tokens)->type != PIPE)
	{
		if ((*tokens)->type == WORD)
		{
			command->argv[i] = ft_strdup((*tokens)->value);
			*tokens = (*tokens)->next;
			i++;
		}
		else if (is_redir((*tokens)->type))
		{
			if (append_redir(lst_ext, tokens, command))
				return (1);
		}
	}
	command->argv[i] = NULL;
	command->next = NULL;
	return(0);
}

int	append_redir(int *lst_ext, t_token **tokens, t_cmd *command)
{
	if ((*tokens)->type == REDIR_IN)
		command->redirs->type = REDIR_IN;
	else if ((*tokens)->type == REDIR_OUT)
		command->redirs->type = REDIR_OUT;
	else if ((*tokens)->type == REDIR_APPEND)
		command->redirs->type = REDIR_APPEND;
	else if ((*tokens)->type == HEREDOC)
		command->redirs->type = HEREDOC;
	*tokens = (*tokens)->next;
	if (!(*tokens))
		return (NULL);
	else
		command->redirs->file = ft_strdup((*tokens)->value);
	return (*lst_ext);
}

int	parse_command(int *lst_ext, t_token **tokens, t_cmd *command)
{
	int		size;
	t_token	*current;

	size = 0;
	current = *tokens;
	while (current && current->type != PIPE)
	{
		if (current->type == WORD)
			size++;
		else if (is_redir(current->type))
			current = current->next;
		if (current)
			current = current->next;
	}
	// check if the pipe has a command afterwards
	command->argv = malloc(sizeof(char *) * (size + 1));
	if (!command->argv)
		return (1);
	filling (tokens, commands);
	return (*lst_ext);
}

t_cmd	*parse(int *lst_ext, t_token **tokens)
{
	t_cmd	*commands;
	t_cmd	*current_cmd;

	commands = NULL;
	while (*tokens != NULL)
	{
		current_cmd = new_cmd();
		if (!current_cmd)
			return (NULL);
		if (parse_command(lst_ext, tokens, current_cmd) == SYNTAX_ERROR)
		{
			// free function for tokens, new_cmd and commands
			return (NULL);
		}
		add_cmd(&commands, current_cmd);
		if (*tokens && (*tokens)->type == PIPE)
		{
			*tokens = (*tokens)->next;
			if (*tokens == NULL)
				return (printf("minishell: syntax error near unexpected token `|'\n"),
					*lst_ext = 2, NULL);
		}
	}
	// function that frees my tokens
	return (commands);
}
