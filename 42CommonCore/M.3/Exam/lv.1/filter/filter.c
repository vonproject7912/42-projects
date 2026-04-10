/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 09:15:56 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:07:38 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	my_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && (i < n - 1))
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char *av[])
{
	int		i;
	int		j;
	char	c;
	int		len;
	int		reading;
	char	str[10000];

	i = 0;
	reading = 0;
	if (ac == 2)
	{
		len = my_strlen(av[1]);
		// read 1 byte from stdin (0) as first guard check
		reading = read(0, &c, 1);
		// handle errors
		if (reading <= 0)
		{
			perror("Error: ");
			return (1);
		}
		// acutally reading and storing
		while (reading)
		{
			str[i] = c;
			reading = read(0, &c, 1);
			i++;
		}
		str[i] = '\0';
		i = 0;
		while (str[i])
		{
			j = 0;
			// if the occurence is found write
			if (my_strncmp(av[1], &str[i], len) == 0)
			{
				// compare with the lenght of the pattern
				while (j < len)
				{
					write(1, "*", 1);
					j++;
					i++;
				}
			}
			// otherwise just write
			else
			{
				write(1, &str[i], 1);
				i++;
			}
		}
	}
	else
		return (1);
}
