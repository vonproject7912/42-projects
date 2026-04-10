/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:09:40 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:39:47 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void	ft_tab_mult(int nb)
{
	int	i;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " * ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		ft_putnbr(nb * i);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_tab_mult(ft_atoi(av[1]));
	else
		write(1, "\n", 1);
	return (0);
}
