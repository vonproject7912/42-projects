/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 09:58:12 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/17 10:54:21 by vonpr            ###   ########.fr       */
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

void	err(int *lst_ext, char *str)
{
	ft_putstr(2, str);
	*lst_ext = 2;
}
