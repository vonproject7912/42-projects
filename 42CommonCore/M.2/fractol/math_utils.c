/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:33:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:53:22 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// simple produit en croix
double	my_scale(int pixel, int max_pixel, double new_min, double new_max)
{
	return (new_min + (new_max - new_min) * (double)pixel / max_pixel);
}

// adding the constante
t_complex	adding_c(t_complex z, t_complex c)
{
	t_complex	z2;

	z2.real = z.real + c.real;
	z2.imaginary = z.imaginary + c.imaginary;
	return (z2);
}

// squaring a number formula
t_complex	square_complex(t_complex z1)
{
	t_complex	z2;

	z2.real = (z1.real * z1.real) - (z1.imaginary * z1.imaginary);
	z2.imaginary = 2 * z1.real * z1.imaginary;
	return (z2);
}
