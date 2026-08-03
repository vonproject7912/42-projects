/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:17:37 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 15:27:04 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// function for any pipe related error
void	pipe_err(void)
{
	ft_putstr(2, "minishell: syntax error near unexpected token '|'\n");
}

// function for any redirection related error
void	redir_err(void)
{
	ft_putstr(2, "minishell: syntax error near unexpected token 'newline'\n");
}

// function to check if the last token is correct
// and not a redirection without a file
int	last_token_check(t_token *current)
{
	if (current->type == PIPE)
		return (pipe_err(), 1);
	else if (current->type != WORD && current->type != PIPE)
		return (redir_err(), 1);
	return (0);
}

// function that checks for any syntaxe errors
int	syntax_check(t_token *tokens)
{
	t_token	*current;
	t_token	*next_current;

	current = tokens;
	// check if the first token is a pipe
	if (current->type == PIPE)
		return (pipe_err(), 1);
	// loop over each token
	while (current->next != NULL)
	{
		// if there is a pipe
		if (current->type == PIPE)
		{
			next_current = current->next;
			// and the next element is a pipe or a redirection
			if (next_current->type == PIPE || next_current->type != WORD)
				return (pipe_err(), 1); // pipe error
		}
		// or if it's a redirection
		else if (current->type != PIPE && current->type != WORD)
		{
			next_current = current->next;
			// and the next elemnt is a pipe or a redirection
			if (next_current->type == PIPE || next_current->type != WORD)
				return (redir_err(), 1); // redirection error
		}
		current = current->next;
	}
	// check for the last token
	if (last_token_check(current))
		return (1);
	return (0);
}
