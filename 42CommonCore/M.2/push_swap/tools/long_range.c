/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:45:35 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:00:42 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	atol(const char *str)
{
	int		i;
	long	res;
	int		signe;

	i = 0;
	res = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signe);
}

// range checking
int	is_range(long nbr)
{
	if (nbr > INT_MAX)
		return (1);
	else if (nbr < INT_MIN)
		return (1);
	else
		return (0);
}
