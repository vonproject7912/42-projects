/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:19:22 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 15:09:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// create allocate and init a new cmd
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

// add a new new command to my linked list
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

// samll error function that sets the last exit to 1
// for malloc fails and print an error message
void	malloc_err(t_shell *shell)
{
	shell->last_exit = 1;
	ft_putstr(2, "minishell: malloc error\n");
}
