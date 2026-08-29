/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 08:48:43 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/29 08:49:17 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void free_mlx(t_game *game)
{
	int i;

	i = 0;
	// free the image before the connection
	if (game->screen.img_ptr)
		mlx_destroy_image(game->mlx_connection, game->screen.img_ptr);
	// free the window
	if (game->window)
    	mlx_destroy_window(game->mlx_connection, game->window);
	// free the textures
	while (i < 4)
	{
		if (game->textures[i].img.img_ptr)
        	mlx_destroy_image(game->mlx_connection, game->textures[i].img.img_ptr);
		i++;
	}
	// free the connection itself
	if (game->mlx_connection)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
	}
}
