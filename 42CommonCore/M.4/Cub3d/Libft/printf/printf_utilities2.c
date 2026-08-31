/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utilities2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhadra <mokhadra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 05:13:06 by mokhadra          #+#    #+#             */
/*   Updated: 2025/12/22 10:04:21 by mokhadra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_args(const char *s, va_list *args, int *i)
{
	int	len;

	len = 0;
	if (s[*i] == 's')
		len += ft_putstr_printf(va_arg(*args, char *));
	else if (s[*i] == 'c')
		len += ft_putchar_printf(va_arg(*args, int));
	else if (s[*i] == 'p')
		len += print_addr(va_arg(*args, void *));
	else if (s[*i] == 'd')
		len += ft_putnbr_printf(va_arg(*args, int));
	else if (s[*i] == 'u')
		len += ft_putnbr_u(va_arg(*args, unsigned int));
	else if (s[*i] == 'i')
		len += ft_putnbr_printf(va_arg(*args, int));
	else if (s[*i] == 'x')
		len += ft_putnbr_hexa(va_arg(*args, unsigned int));
	else if (s[*i] == 'X')
		len += ft_putnbr_hexa_maj(va_arg(*args, unsigned int));
	else
		len += ft_putchar_printf(s[*i]);
	return (len);
}

int	print_addr(void *addr)
{
	int				i;
	unsigned long	c;

	if (!addr)
		return (write(1, "(nil)", 5));
	i = 0;
	c = (unsigned long)addr;
	write(1, "0x", 2);
	i += 2;
	i += ft_putnbr_hexa(c);
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr_u(n / 10);
		i += ft_putnbr_u(n % 10);
	}
	else
		i += ft_putchar_printf(n + '0');
	return (i);
}
