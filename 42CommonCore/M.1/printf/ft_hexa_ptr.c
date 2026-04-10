/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:54:28 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:28:59 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_ptr(uintptr_t nbr)
{
	char		*base;
	uintptr_t	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr > 15)
		i += ft_hexa_ptr(nbr / 16);
	i += ft_print_char(base[nbr % 16]);
	return (i);
}
