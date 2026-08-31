/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhadra <mokhadra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:08:31 by mokhadra          #+#    #+#             */
/*   Updated: 2025/12/22 10:03:08 by mokhadra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	write(1, &ch, 1);
	return (1);
}

int	ft_putstr_printf(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_printf(int nb)
{
	int		i;
	long	n;

	i = 0;
	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	if (n >= 0 && n <= 9)
		i += ft_putchar_printf(n + '0');
	if (n > 9)
	{
		i += ft_putnbr_printf(n / 10);
		i += ft_putnbr_printf(n % 10);
	}
	return (i);
}

int	ft_putnbr_hexa(unsigned long nb)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		i += ft_putnbr_hexa(nb / 16);
		i += ft_putnbr_hexa(nb % 16);
	}
	else
		i += ft_putchar_printf(base[nb]);
	return (i);
}

int	ft_putnbr_hexa_maj(unsigned long nb)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		i += ft_putnbr_hexa_maj(nb / 16);
		i += ft_putnbr_hexa_maj(nb % 16);
	}
	else
		i += ft_putchar_printf(base[nb]);
	return (i);
}

// int main(void)
// {
// 	//printf("%d", ft_check_base("123451"));
// 	//ft_putnbr_hexa(-255);
// 	//printf("%d\n",
// 	print_addr("je pense");
// }