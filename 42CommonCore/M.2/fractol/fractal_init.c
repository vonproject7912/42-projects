/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:33:05 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:52:58 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// error function
void	failed_malloc(void)
{
	perror("Malloc failed");
	exit(EXIT_FAILURE);
}

// init my folder data
void	data_init(t_file *fractal)
{
	fractal->zoom = 1;
	fractal->x_shift = 0;
	fractal->y_shift = 0;
	fractal->escaped_value = 16;
	fractal->fractal_iteration = 200;
}

// Create the window
void	fractal_init(t_file *fractal)
{
	// connect to the x server
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		failed_malloc();
	// create the winwdow
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		failed_malloc();
	}
	// create the image
	fractal->image.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->image.img)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		failed_malloc();
	}
	// get the adress to the first pixel
	fractal->image.address = mlx_get_data_addr(fractal->image.img,
			&fractal->image.bpp, &fractal->image.size_line,
			&fractal->image.endian);
	// call for event handling
	events_handling(fractal);
	// init my data
	data_init(fractal);
}
