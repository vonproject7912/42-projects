/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:13:22 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:39:16 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int	n;

	n = a;
	// check if they have a common denominateur of a and b
	while (n > 0)
	{
		// if so print and return
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return ;
		}
		--n;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		pgcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
}
