/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:19:22 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/21 11:32:55 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	add_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	free_tokens(t_token **tokens)
{
	t_token	*current;

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

void	malloc_err(int *lst_ext)
{
	*lst_ext = 1;
	ft_putstr(2, "minishell: malloc error\n");
}

int	is_redir(t_type type)
{
	if (type == REDIR_IN || type == REDIR_OUT || type == REDIR_APPEND
		|| type == HEREDOC)
		return (1);
	else
		return (0);
}
