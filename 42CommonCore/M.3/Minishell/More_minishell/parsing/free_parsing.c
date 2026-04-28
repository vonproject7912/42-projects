/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:09:47 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/22 15:43:20 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// function that frees my tokens
void	free_tokens(t_token **tokens)
{
	t_token	*current;

	// small check
	if (!tokens || !(*tokens))
		return ;
	// loop over each token to free them
	while (*tokens)
	{
		// save the next one
		current = (*tokens)->next;
		// free the previous one's value
		free((*tokens)->value);
		// free the previous one itself
		free(*tokens);
		// go to the next token
		*tokens = current;
	}
}

// function that frees a redirection linked list
void	free_redir(t_cmd **commands)
{
	t_redir	*current_redir;

	// same process as free_tokens
	while ((*commands)->redirs)
	{
		current_redir = (*commands)->redirs->next;
		free((*commands)->redirs->file);
		free((*commands)->redirs);
		(*commands)->redirs = current_redir;
	}
}

// free my commands linked list for each 
// their argv and potential redirections
void	free_commands(t_cmd **commands)
{
	int		i;
	t_cmd	*current;

	// small check
	if (!commands || !(*commands))
		return ;
	// loop over each command
	while (*commands)
	{
		i = 0;
		// save the next one
		current = (*commands)->next;
		// free the previous one's argv
		while ((*commands)->argv[i])
		{
			free((*commands)->argv[i]);
			i++;
		}
		free((*commands)->argv);
		// if their are redirections call 
		// for my redir free function
		if ((*commands)->redirs)
			free_redir(commands);
		// free the whole previous command
		free(*commands);
		// next one
		*commands = current;
	}
}
