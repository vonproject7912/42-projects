/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:28:36 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/13 15:05:10 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lexer(char *str, int *lst_ext)
{
	int		i;
	t_token	*my_tokens;

	i = 0;
	my_tokens = NULL;  // init my linked list
	if (quotes_checking(str)) // check for unclosed quotes
		return (err(lst_ext, "minishell: syntax error: unclosed quote"), NULL);
	while (str[i] == ' ' || str[i] == '\t')
		i++; // skip space
	if (!str[i])
	    return (NULL); // early return for empty input
	while (str[i]) // loop and fill my tokens
	{
	    if (str[i] == '\'')
	        // function for single quotes
	    else if (str[i] == '"')
	        // function for double quotes
	    else if (str[i] == ' ' || str[i] == '\t')
	        i++;
	    else if (is_operator(str[i]))
	        // function handle_operators
	    else
	        // function for regular words until space or operator
	}
	return (my_tokens);
}
