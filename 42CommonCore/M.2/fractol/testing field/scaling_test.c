/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:23:27 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:52:37 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double	my_scale(int pixel, int max_pixel, double new_min, double new_max)
{
	return (new_min + (new_max - new_min) * (double)pixel / max_pixel);
}

double	scale(double unscaled_num, double new_min, double new_max,
		double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

int	main(void)
{
	printf("My scale: %f\n", my_scale(17.4, 800, -2, 2));
	printf("Complexe scale: %f", scale(17.4, -2, 2, 0, 800));
	return (0);
}
