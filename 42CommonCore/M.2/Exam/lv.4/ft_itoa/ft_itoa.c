/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:20:00 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:48:26 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	count_nbr(size_t nbr)
{
	long	nbrs;
	size_t	count;

	count = 0;
	nbrs = nbr;
	if (nbrs < 0)
		count = 1;
	if (nbrs == 0)
		return (1);
	while (nbrs)
	{
		nbrs /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	count;
	char	*save;

	nbr = n;
	count = count_nbr(n);
	save = malloc(sizeof(char) * (count + 1));
	if (!save)
		return (NULL);
	save[count] = '\0';
	count--;
	if (nbr == 0)
		return (save[0] = '0', save);
	if (nbr < 0)
	{
		nbr *= -1;
		save[0] = '-';
	}
	while (nbr > 0)
	{
		save[count] = (nbr % 10) + '0';
		nbr /= 10;
		count--;
	}
	return (save);
}
