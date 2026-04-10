/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:18:23 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:47:54 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	is_prime(unsigned int n)
{
	unsigned int	i;

	i = 2;
	if (n < 2)
		return (0);
	while (i <= n) //!!!!!
	{
		if (n % i == 0)
			return (0);
		i++;
	} //!!!!!!!
	return (1);
}

int	main(int ac, char **av)
{
	int	nb;
	int	sum;

	nb = 0;
	sum = 0;
	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		// check if he is premier
		while (nb)
		{
			// if so we sum it
			if (is_prime(nb))
				sum += nb;
			nb--;
		}
		// print the final sum
		ft_putnbr(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
