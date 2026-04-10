/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:15:13 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:32:52 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i;
	int	j;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				while (j < av[1][i] - 64)
				{
					write(1, &av[1][i], 1);
					j++;
				}
			}
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				while (j < av[1][i] - 96)
				{
					write(1, &av[1][i], 1);
					j++;
				}
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
