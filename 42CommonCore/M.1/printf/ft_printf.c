/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 03:12:58 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:29:18 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function that identifies the type / format of the argument
// and calls the right function for it
int	printf_type(char type, va_list ap)
{
	size_t	count;

	// uses va_arg to use an argument after each call
	count = 0;
	// character
	if (type == 'c')
		return (count += ft_print_char(va_arg(ap, int)));
	// string
	else if (type == 's')
		return (count += ft_print_str(va_arg(ap, char *)));
	// a signed int
	else if (type == 'd' || type == 'i')
		return (count += ft_print_putnbr(va_arg(ap, int)));
	// adress of a pointer
	else if (type == 'p')
		return (count += ft_print_adress(va_arg(ap, void *)));
	// unsigned int
	else if (type == 'u')
		return (count += ft_print_positf_putnbr(va_arg(ap, unsigned int)));
	// unsigned int as lowercase hex
	else if (type == 'x')
		return (count += ft_print_hexa(va_arg(ap, unsigned int)));
	// unsigned int as uppercase hex
	else if (type == 'X')
		return (count += ft_print_up_hexa(va_arg(ap, unsigned int)));
	// otherwise just print the identifier
	else
		return (count += ft_print_char(type));
	return (count);
}

// main function
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	// initialize the start of arguments
	va_start(ap, format);
	// check for the first parameter
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		// format found call for printf_type
		if (*format == '%')
			count += printf_type(*(++format), ap);
		// otherwise just write
		else
			count += write(1, format, 1);
		format++;
	}
	// set the use of variadic argument to an end / clean up
	va_end(ap);
	return (count);
}
