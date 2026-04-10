/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:49:19 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:37:01 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	unionn(char *s1, char *s2)
{
	int	i;
	int	tab[256] = {0};

	i = 0;
	while (s1[i])
	{
		if (tab[(int)s1[i]] == 0)
		{
			tab[(int)s1[i]] = 1;
			write(1, &s1[i], 1);
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (tab[(int)s2[i]] == 0)
		{
			tab[(int)s2[i]] = 1;
			write(1, &s2[i], 1);
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 3)
		unionn(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
