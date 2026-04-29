/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:22:46 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/29 13:47:57 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_var_start(char c)
{
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '_')
		return (1);
	return (0);
}

int	is_var_char(char c)
{
	if (is_var_start(c) || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*append_part(char *result, char *part)
{
	char	*new_result;

	if (!part)
		return (free(result), NULL);
	new_result = ft_strjoin(result, part);
	free(result);
	free(part);
	return (new_result);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nbr;
	int		sign;
	char	buffer[12];

	i = 11;
	nbr = n;
	sign = 1;
	buffer[i--] = '\0';
	if (nbr == 0)
		buffer[i--] = '0';
	if (nbr < 0)
	{
		sign = -1;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		buffer[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign < 0)
		buffer[i--] = '-';
	return (ft_strdup(&buffer[i + 1]));
}
