/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 08:49:35 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/29 05:48:39 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// mlx connection
int init_mlx(t_game *game)
{
	// init the sizes
	game->screen.width = WIDTH;
	game->screen.height = HEIGHT;
	// init the mlx connection to the x server
	game->mlx_connection = mlx_init(); 
	if (game->mlx_connection == NULL) // small check
		return (1);
	// create the window
	game->window = mlx_new_window(game->mlx_connection, WIDTH, HEIGHT, "wtf");
	if (!game->window) // failed window creation
		return (1);
	// Screen / image creation
	game->screen.img_ptr = mlx_new_image(game->mlx_connection, WIDTH, HEIGHT);
	if (game->screen.img_ptr == NULL)
		return (1);
	// get the screen address
	game->screen.addr = mlx_get_data_addr(game->mlx_connection, 
		&game->screen.bits_per_pixel, &game->screen.line_length, &game->screen.endian);
	return (0);
}

void free_game(t_game *game)
{
	// free the image before the connection
	if (game->screen.img_ptr)
		mlx_destroy_image(game->mlx_connection, game->screen.img_ptr);
	// free the window
	if (game->window)
		mlx_destroy_window(game->mlx_connection, game->window);
	// free the connection itself
	if (game->mlx_connection)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
	}
}

// init player
// init texture
// init picture
