/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 10:19:47 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/28 10:35:17 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// event handling
void even_handling(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, key_handling, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, Close_window, game);
}

int key_handling(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		game->player.pos_y -= 0.7;
	if (keysym == KEY_A)
		game->player.pos_x -= 0.7;
	if (keysym == KEY_S)
		game->player.pos_y += 0.7;
	if (keysym == KEY_D)
		game->player.pos_x += 0.7;
	if (keysym == KEY_LEFT)
		game->player.dir_x -= 0.4;
	if (keysym == KEY_RIGHT)
		game->player.dir_x += 0.4;
	if (keysym == KEY_ESC)
		Close_window(game);
	// randering function
	return (0);
}

int Close_window(t_game *game)
{
	int i;

	i = 0;
	while (i < 4)
		mlx_destroy_image(game->mlx_connection, game->textures[i++].img.img_ptr);
	mlx_destroy_image(game->mlx_connection, game->screen.img_ptr);
	mlx_destroy_window(game->mlx_connection, game->window);
	mlx_destroy_display(game->mlx_connection);
	free(game->mlx_connection);
	exit(EXIT_SUCCESS);
}
