/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:34:15 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:53:30 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Julia rendering
void	handle_pixel_julia(int x, int y, t_file *fractal)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	i = 0;
	// set the constantes
	c.real = fractal->julia_x;      // av[2]
	c.imaginary = fractal->julia_y; // av[3]
	// for Julia:
	// z takes the mapping of the pixel z(x, y)
	z.real = my_scale(x, WIDTH, -2, +2) * fractal->zoom + fractal->x_shift;
	z.imaginary = my_scale(y, HEIGHT, +2, -2) * fractal->zoom
		+ fractal->y_shift;
	// iterate the current pixel into the formula
	while (i < fractal->fractal_iteration)
	{
		// apply z = z^2 + c
		z = adding_c(square_complex(z), c);
		// check if the value escaped
		if ((z.real * z.real) + (z.imaginary
				* z.imaginary) > fractal->escaped_value)
		{
			// get the color acordingly (with the time it took to escape)
			color = get_smooth_color(i, z, fractal);
			// put the pixel into the image
			my_pixel_put(x, y, fractal->image, color);
			return ;
		}
		i++;
	}
	// value hasn't escaped = is inside the set
	my_pixel_put(x, y, fractal->image, WHITE);
}

// Mandelbrot rendering
void	handle_pixel_mandelbrot(int x, int y, t_file *fractal)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	i = 0;
	z.real = 0;
	z.imaginary = 0;
	// for Mandelbrot
	// pixel mapping (x, y) to the constant 'c'
	c.real = my_scale(x, WIDTH, -2, +2) * fractal->zoom + fractal->x_shift;
		// x the real part
	c.imaginary = my_scale(y, HEIGHT, +2, -2) * fractal->zoom              
		// z the imaginary part
		+ fractal->y_shift;
	// iterate the current pixel into the formula
	while (i < fractal->fractal_iteration)
	{
		// apply z = z^2 + c
		z = adding_c(square_complex(z), c);
		// check if the value escaped
		if ((z.real * z.real) + (z.imaginary
				* z.imaginary) > fractal->escaped_value)
		{
			// get the color acordingly (with the time it took to escape)
			color = get_smooth_color(i, z, fractal);
			// put the pixel into the image
			my_pixel_put(x, y, fractal->image, color);
			return ;
		}
		i++;
	}
	// value hasn't escaped = is inside the set
	my_pixel_put(x, y, fractal->image, WHITE);
}

// main fractal rendering function:
// iterates through every pixel of the window and calls the
// right handler based on the fractal
void	fractal_render(t_file *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// Mandelbrot set
			if (!ft_strncmp(fractal->name, "mandelbrot", 10))
				handle_pixel_mandelbrot(x, y, fractal);
			// Julia set
			else if (!ft_strncmp(fractal->name, "julia", 5))
				handle_pixel_julia(x, y, fractal);
			x++;
		}
		y++;
	}
	// push the finished image buffer to the window
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->image.img, 0, 0);
}
