/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:12:30 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:39:08 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	mini_putchar(char c)
{
	write(1, &c, 1);
}

void	mini_putnbr(int nbr)
{
	if (nbr > 9)
		mini_putnbr(nbr / 10);
	mini_putchar((nbr % 10) + '0');
}

int	main(int ac, char *av[])
{
	(void)av;
	if (ac == 1)
		write(1, "\n", 1);
	else
		mini_putnbr(ac);
	return (0);
}
