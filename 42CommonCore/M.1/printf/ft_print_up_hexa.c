/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_up_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:55:37 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:29:16 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_up_hexa(long nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nbr < 0)
	{
		nbr *= -1;
		i += ft_print_char('-');
	}
	if (nbr > 15)
		i += ft_print_up_hexa(nbr / 16);
	i += ft_print_char(base[nbr % 16]);
	return (i);
}
