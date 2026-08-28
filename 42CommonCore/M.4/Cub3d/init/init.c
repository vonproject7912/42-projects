/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 08:49:35 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/28 09:53:19 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int init_mlx(t_game *game)
{
	// init the mlx connection to the x server
	game->mlx_connection = mlx_init(); 
	if (game->mlx_connection == NULL) // small check
		return (1);
	// create the window
	game->window = mlx_new_window(game->mlx_connection, WIDTH, HEIGHT, "wtf");
	if (!game->window) // failed window creation
	{
		mlx_destroy_display(game->mlx_connection); // unlink 
		free(game->mlx_connection); // free
		return (1);
	}
	// Screen / image creation
	game->screen.img_ptr = mlx_new_image(game->mlx_connection, WIDTH, HEIGHT);
	if (game->screen.img_ptr == NULL)
	{
		mlx_destroy_window(game->mlx_connection, game->window);
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		return (1);
	}
	// get the screen address
	game->screen.addr = mlx_get_data_addr(game->mlx_connection, 
		&game->screen.bits_per_pixel, &game->screen.line_length, &game->screen.endian);
	return (0);
}

