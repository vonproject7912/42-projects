/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhadra <mokhadra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:40:38 by mokhadra          #+#    #+#             */
/*   Updated: 2026/06/07 12:40:40 by mokhadra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	buf[12];
	int		i;
	long	nb;
	int		sign;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	i = 11;
	buf[i--] = '\0';
	if (nb == 0)
		buf[i--] = '0';
	while (nb > 0)
	{
		buf[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign)
		buf[i--] = '-';
	return (ft_strdup(&buf[i + 1]));
}
