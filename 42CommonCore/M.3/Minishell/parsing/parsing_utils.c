/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 09:45:59 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/20 12:50:46 by vonpr            ###   ########.fr       */
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

int	is_redir(t_type type)
{
	if (type == REDIR_IN || type == REDIR_OUT || type == REDIR_APPEND
		|| type == HEREDOC)
		return (1);
	else
		return (0);
}
