/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 05:15:09 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:16:35 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count the room for the string of numbers
static int	count_nbr(size_t nbr)
{
	long	nbrs;
	size_t	count;

	count = 0;
	nbrs = nbr;
	// for negative nbr
	if (nbrs < 0)
		count = 1;
	// for nbr = 0
	if (nbrs == 0)
		return (1);
	// counting for nbr
	while (nbrs)
	{
		nbrs /= 10;
		count++;
	}
	return (count);
}

// convert from integer to atoi
char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	size_t	count;

	nbr = n;
	count = count_nbr(n);
	// allocate the string
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	// put the int into the string
	str[count] = '\0';
	// step back
	count--;
	// 0 case handling
	if (nbr == 0)
		return (str[0] = '0', str);
	// if negative place - at the start
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	// convert each number into ascii
	while (nbr > 0)
	{
		str[count] = (nbr % 10) + '0';
		nbr /= 10;
		count--;
	}
	return (str);
}
