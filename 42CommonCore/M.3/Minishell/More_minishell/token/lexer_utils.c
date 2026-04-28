/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:13:26 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/18 11:40:00 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// function that check if all the quotes are closed
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

// identify wheter there are some operators
int	is_operator(char c)
{
	if ((c == '|') || (c == '<') || (c == '>'))
		return (1);
	return (0);
}

// assigned the token value for each operators instead of just NULL
// but I'm unsure if this function trully is necessary but it's more for safety
void	value_assign(int *i, char *str, t_token *token)
{
	if (str[*i] == '|')
		token->value = ft_strndup("|", 1);
	else if (str[*i] == '>' && str[*i + 1] == '>')
		token->value = ft_strndup(">>", 2);
	else if (str[*i] == '<' && str[*i + 1] == '<')
		token->value = ft_strndup("<<", 2);
	else if (str[*i] == '<')
		token->value = ft_strndup("<", 1);
	else if (str[*i] == '>')
		token->value = ft_strndup(">", 1);
	if (token->type == REDIR_APPEND || token->type == HEREDOC)
		*i += 2;
	else
		*i += 1;
}
