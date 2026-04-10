/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:52:42 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:29:05 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(long nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		i += ft_print_char('-');
	}
	if (nbr > 15)
		i += ft_print_hexa(nbr / 16);
	i += ft_print_char(base[nbr % 16]);
	return (i);
}
