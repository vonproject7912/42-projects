/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:34:08 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:53:26 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// generates a color using Bernstein polynomials
int	get_color(double i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	// if the point is inside the set = black dot
	if (i == max_iter || i < 0)
		return (BLACK);
	// normalize the iteration count to a scale of 0.0 to 1.0
	t = (double)i / max_iter;
	// calculate color channels using polynomial curves
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	// combine RGB into a single 32-bit integer (Format: 0xRRGGBB)
	return (r << 16 | g << 8 | b);
}

// writes a specific color to the image buffer at coordinates (x, y)
void	my_pixel_put(int x, int y, t_image image, int color)
{
	int	offset;

	/* Calculate the memory offset:
		1. (y * size_line) skips all the bytes of previous rows
		2. (x * (bpp / 8)) moves to the correct pixel in the current row */
	offset = (y * image.size_line) + (x * (image.bpp / 8));
	// set the color at the image pixel's adress
	*(unsigned int *)(image.address + offset) = color;
}

// smmoth down the color depending on how fast the value escaped
int	get_smooth_color(int i, t_complex z, t_file *fractal)
{
	double	smooth_i;

	/* The Re-normalization Formula:
		Uses log(log(magnitude)) to determine the fractional part of the escape
		This bridges the gap between discrete iteration i and i + 1 */
	smooth_i = i + 1 - log(log(sqrt(z.real * z.real + z.imaginary
					* z.imaginary))) / log(2);
	// Ensure we don't pass negative values to the color function
	if (smooth_i < 0)
		smooth_i = 0;
	// pass the smooth decimal value to get the final RGB color
	return (get_color(smooth_i, fractal->fractal_iteration));
}
