/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:52:57 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:29:01 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_adress(void *ptrr)
{
	size_t		i;
	uintptr_t	ptr;

	i = 0;
	ptr = (uintptr_t)ptrr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	ft_print_str("0x");
	i += 2;
	i += ft_hexa_ptr(ptr);
	return (i);
}
