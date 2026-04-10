/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:11:53 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:31:28 by vonpr            ###   ########.fr       */
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

int	main(void)
{
	int	nbr;

	nbr = 1;
	while (nbr < 100)
	{
		if ((nbr % 3 == 0) && (nbr % 5 == 0))
			write(1, "fizzbuzz", 8);
		else if (nbr % 3 == 0)
			write(1, "fizz", 4);
		else if (nbr % 5 == 0)
			write(1, "buzz", 4);
		else
			mini_putnbr(nbr);
		write(1, "\n", 1);
		nbr++;
	}
	return (0);
}
