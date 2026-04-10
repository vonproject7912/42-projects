/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:47:02 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:35:47 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	nbr;

	nbr = 1;
	if (n == 0)
		return (0);
	while (1)
	{
		if (nbr == n)
			return (1);
		else if (nbr > n)
			return (0);
		nbr *= 2;
	}
}
