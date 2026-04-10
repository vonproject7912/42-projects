/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:32:56 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:52:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// handles key presses, exit cross and mousse
void	events_handling(t_file *fractal)
{
	mlx_hook(fractal->mlx_window, KeyRelease, KeyReleaseMask, key_handling,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		exit_handling, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handling,
		fractal);
}

// handle all my key presses and renders again after each presses
int	key_handling(int keysym, t_file *fractal)
{
	if (keysym == XK_Escape)
		exit_handling(fractal);
	else if (keysym == XK_Left)
		fractal->x_shift -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->x_shift += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->y_shift += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->y_shift -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->fractal_iteration += 10;
	else if (keysym == XK_minus)
		fractal->fractal_iteration -= 10;
	fractal_render(fractal);
	return (0);
}

// exiting function
int	exit_handling(t_file *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

// zooming in
int	mouse_handling(int button, int x, int y, t_file *fractal)
{
	(void)x;
	(void)y;
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}
