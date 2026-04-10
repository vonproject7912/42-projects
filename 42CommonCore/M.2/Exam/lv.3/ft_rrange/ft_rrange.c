/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:07:40 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:46:31 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	*wrdb;

	i = 0;
	if (start == end)
		return (0);
	else if (end > start)
	{
		wrdb = malloc(sizeof(int) * (end - start) + 1);
		if (!wrdb)
			return (0);
		while (end >= start)
		{
			wrdb[i] = end;
			i++;
			end--;
		}
	}
	else if (end < start)
	{
		wrdb = malloc(sizeof(int) * (start - end) + 1);
		if (!wrdb)
			return (0);
		while (start >= end)
		{
			wrdb[i] = end;
			i++;
			end++;
		}
	}
	return (wrdb); // when you return an array, you're actually,
	// returning a pointer to the first element
}

int	main(void)
{
	int	i;
	int	end;
	int	*tab;
	int	size;
	int	start;

	start = 15;
	end = -7;
	tab = ft_rrange(start, end);
	i = 0;
	if (end > start)
		size = end - start;
	else if (start > end)
		size = start - end;
	else
		return (0);
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
