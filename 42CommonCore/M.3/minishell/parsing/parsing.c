/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazeer <mnazeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:27:57 by mosriji           #+#    #+#             */
/*   Updated: 2026/05/04 18:53:42 by mnazeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_str(t_token **tokens, t_cmd *command)
{
	int		size;
	t_token	*current;

	size = 0;
	current = (*tokens);
	while (current && current->type != PIPE)
	{
		if (current->type == WORD)
			size++;
		current = current->next;
	}
	command->argv = malloc(sizeof(char *) * (size + 1));
	if (!command->argv)
		return (1);
	command->quotes = malloc(sizeof(int) * (size + 1));
	if (!command->quotes)
	{
		free(command->argv);
		command->argv = NULL;
		return (1);
	}
	return (0);
}

int	cmd_fill(t_token **tokens, t_cmd *command)
{
	int	i;

	i = 0;
	if (add_str(tokens, command))
		return (1);
	while ((*tokens) && (*tokens)->type != PIPE)
	{
		if ((*tokens)->type == WORD)
		{
			command->argv[i] = ft_strdup((*tokens)->value);
			if (!command->argv[i])
				return (1);
			command->quotes[i] = (*tokens)->quote;
			(*tokens) = (*tokens)->next;
			i++;
		}
		else if ((*tokens)->type != WORD)
		{
			if (append_redir(tokens, command))
				return (1);
		}
	}
	command->argv[i] = NULL;
	command->next = NULL;
	return (0);
}

t_cmd	*append_cmd(t_shell *shell, t_token **tokens, t_cmd *commands)
{
	t_cmd	*current_cmd;

	if (!(*tokens))
		return (NULL);
	while ((*tokens))
	{
		current_cmd = new_cmd();
		if (!current_cmd)
			return (malloc_err(shell), free_commands(&commands), NULL);
		if (cmd_fill(tokens, current_cmd))
			return (malloc_err(shell), free_commands(&current_cmd),
				free_commands(&commands), NULL);
		if ((*tokens) && (*tokens)->type == PIPE)
			(*tokens) = (*tokens)->next;
		add_cmd(&commands, current_cmd);
	}
	return (commands);
}

t_cmd	*parse(t_shell *shell, t_token **tokens)
{
	t_token	*tmp;
	t_cmd	*commands;

	commands = NULL;
	tmp = *tokens;
	if (syntax_check(*tokens))
	{
		shell->last_exit = 2;
		return (free_tokens(tokens), NULL);
	}
	commands = append_cmd(shell, &tmp, commands);
	free_tokens(tokens);
	return (commands);
}
