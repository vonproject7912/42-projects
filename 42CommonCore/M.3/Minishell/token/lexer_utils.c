/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:13:26 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/17 16:05:06 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quotes_checking(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (!str[i])
				return (1);
		}
		else if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				i++;
			if (!str[i])
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_operator(char c)
{
	if ((c == '|') || (c == '<') || (c == '>'))
		return (1);
	return (0);
}

void	token_routine(int *i, int *adj, char *str, t_token **my_tokens)
{
	if (str[i++] == ' ' || str[i++] == '\t')
	{
		adj = 0;
		i++;
	}
	else if (str[i] == '\'')
		handle_single_quote(&i, &adj, str, &my_tokens);
	else if (str[i] == '"')
		handle_double_quote(&i, &adj, str, &my_tokens);
	else if (is_operator(str[i]))
		handle_operators(&i, &adj, str, &my_tokens);
	else
		handle_anything_else(&i, &adj, str, &my_tokens);
}
