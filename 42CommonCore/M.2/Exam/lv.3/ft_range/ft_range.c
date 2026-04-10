/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:08:16 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:46:09 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	*wrdb;

	wrdb = NULL;
	i = 0;
	if (start == end)
		return (0);
	else if (start < end)
	{
		wrdb = malloc(sizeof(int) * (end - start) + 1);
		if (!wrdb)
			return (0);
		while (start < end)
		{
			wrdb[i] = start;
			start++;
			i++;
		}
	}
	else if (end < start)
	{
		wrdb = malloc(sizeof(int) * (start - end) + 1);
		if (!wrdb)
			return (0);
		while (end < start)
		{
			wrdb[i] = start;
			start--;
			i++;
		}
	}
	return (wrdb);
}

int	main(void)
{
	int	i;
	int	end;
	int	size;
	int	start;
	int	*result;

	i = 0;
	start = 1;
	end = 5;
	result = ft_range(start, end);
	size = abs(end - start);
	while (i < size)
	{
		printf("%d ", result[i]);
		i++;
	}
	free(result);
	return (0);
}
