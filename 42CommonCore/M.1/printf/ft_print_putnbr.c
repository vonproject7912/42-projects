/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:52:22 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:29:09 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_putnbr(long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i += ft_print_char('-');
	}
	if (nbr > 9)
	{
		i += ft_print_putnbr(nbr / 10);
	}
	i += ft_print_char((nbr % 10) + '0');
	return (i);
}
