/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:09:47 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 12:19:20 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	free_redir(t_cmd **commands)
{
	t_redir	*current_redir;

	while ((*commands)->redirs)
	{
		current_redir = (*commands)->redirs->next;
		if ((*commands)->redirs->heredoc_fd >= 0)
			close((*commands)->redirs->heredoc_fd);
		free((*commands)->redirs->file);
		free((*commands)->redirs);
		(*commands)->redirs = current_redir;
	}
}

void	free_commands(t_cmd **commands)
{
	int		i;
	t_cmd	*current;

	if (!commands || !(*commands))
		return ;
	while (*commands)
	{
		i = 0;
		current = (*commands)->next;
		while ((*commands)->argv && (*commands)->argv[i])
		{
			free((*commands)->argv[i]);
			i++;
		}
		free((*commands)->argv);
		free((*commands)->quotes);
		if ((*commands)->redirs)
			free_redir(commands);
		free(*commands);
		*commands = current;
	}
}
