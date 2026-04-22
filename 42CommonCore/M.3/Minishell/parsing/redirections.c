/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:51:29 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/22 13:37:46 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*new_redir(void)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->file = NULL;
	redir->next = NULL;
	return (redir);
}

void	add_redir(t_redir **lst, t_redir *new)
{
	t_redir	*current;

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

int	append_redir(t_token **tokens, t_cmd *command)
{
	t_redir	*current_redir;

	current_redir = new_redir();
	if (!current_redir)
		return (1);
	if ((*tokens)->type == REDIR_IN)
		current_redir->type = REDIR_IN;
	else if ((*tokens)->type == REDIR_OUT)
		current_redir->type = REDIR_OUT;
	else if ((*tokens)->type == REDIR_APPEND)
		current_redir->type = REDIR_APPEND;
	else if ((*tokens)->type == HEREDOC)
		current_redir->type = HEREDOC;
	(*tokens) = (*tokens)->next;
	current_redir->file = ft_strdup((*tokens)->value);
	add_redir(&command->redirs, current_redir);
	(*tokens) = (*tokens)->next;
	return (0);
}
