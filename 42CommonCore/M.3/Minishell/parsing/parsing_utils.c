/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:19:22 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/22 13:44:01 by vonpr            ###   ########.fr       */
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
	cmd->quotes = NULL;
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

void	malloc_err(int *lst_ext)
{
	*lst_ext = 1;
	ft_putstr(2, "minishell: malloc error\n");
}
