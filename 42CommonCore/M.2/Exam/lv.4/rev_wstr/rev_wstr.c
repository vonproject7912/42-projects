/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:24:12 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:40:44 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	save;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		i--;
		while (i >= 0)
		{
			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
				i--;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
				i--;
			save = i;
			i++;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			{
				write(1, &av[1][i], 1);
				i++;
			}
			i = save;
			if (i > 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
