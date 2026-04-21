/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:19:28 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/21 15:51:20 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_str(int *lst_ext, t_token **tokens, t_cmd *command)
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
	return (0);
}

int	cmd_fill(int *lst_ext, t_token **tokens, t_cmd *command)
{
	int	i;

	i = 0;
	if (add_str(lst_ext, tokens, command))
		return (1);
	while ((*tokens) && (*tokens)->type != PIPE)
	{
		if ((*tokens)->type == WORD)
		{
			command->argv[i] = ft_strdup((*tokens)->value);
			if (!command->argv[i])
				return (1);
			(*tokens) = (*tokens)->next;
			i++;
		}
		else if ((*tokens)->type != WORD)
		{
			// handles redirections function
		}
	}
	command->argv[i] = NULL;
	command->next = NULL;
	return (0);
}

t_cmd	*append_cmd(int *lst_ext, t_token **tokens, t_cmd *commands)
{
	t_cmd	*current_cmd;

	if (!(*tokens))
		return (NULL);
	while ((*tokens))
	{
		current_cmd = new_cmd();
		if (!current_cmd)
			return (malloc_err(lst_ext), free_commands(&commands), NULL);
		if (cmd_fill(lst_ext, tokens, current_cmd))
			return (malloc_err(lst_ext), free_commands(&current_cmd),
				free_commands(&commands), NULL);
		if ((*tokens) && (*tokens)->type == PIPE)
			(*tokens) = (*tokens)->next;
		add_cmd(&commands, current_cmd);
	}
	return (commands);
}

t_cmd	*parse(int *lst_ext, t_token **tokens)
{
	t_cmd	*commands;

	commands = NULL;
	if (syntax_check(*tokens))
	{
		*lst_ext = 2;
		return (free_tokens(tokens), NULL);
	}
	commands = append_cmd(lst_ext, tokens, commands);
	if (*lst_ext == 1)
		return (free_tokens(tokens), free_commands(&commands), NULL);
	free_tokens(tokens);
	return (commands);
}

///////////////////////////////////////////////////////////////

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
