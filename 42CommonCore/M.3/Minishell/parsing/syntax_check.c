/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:44:51 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/21 11:15:09 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_err(void)
{
	ft_putstr(2, "minishell: syntax error near unexpected token '|'");
}

void	redir_err(void)
{
	ft_putstr(2, "minishell: syntax error near unexpected token 'newline'");
}

int	last_token_check(t_token *current)
{
	if (current->type == PIPE)
		return (pipe_err(), 1);
	else if (current->type != WORD && current->type != PIPE)
		return (redir_err(), 1);
	return (0);
}

int	syntax_check(t_token *tokens)
{
	t_token	*current;
	t_token	*next_current;

	current = tokens;
	if (current->type == PIPE)
		return (pipe_err(), 1);
	while (current->next != NULL)
	{
		if (current->type == PIPE)
		{
			next_current = current->next;
			if (next_current->type == PIPE || next_current->type != WORD)
				return (pipe_err(), 1);
		}
		else if (current->type != PIPE && current->type != WORD)
		{
			next_current = current->next;
			if (next_current->type == PIPE || next_current->type != WORD)
				return (redir_err(), 1);
		}
		current = current->next;
	}
	if (last_token_check(current))
		return (1);
	return (0);
}
