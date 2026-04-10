/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:11:56 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:46:47 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;
	unsigned int	save_a;
	unsigned int	save_b;
	unsigned int	res_gcd;

	if (a == 0 || b == 0)
		return (0);
	save_a = a;
	save_b = b;
	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	res_gcd = a;
	return ((save_a * save_b) / res_gcd);
}
