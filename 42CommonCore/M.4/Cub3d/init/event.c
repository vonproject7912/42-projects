/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 10:19:47 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/30 13:26:17 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// event handling
void	even_handling(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, key_handling, game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, key_release_handling,
		game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, close_window,
		game);
	mlx_loop_hook(game->mlx_connection, render, game);
}

int	key_handling(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		game->player.move_up = 1;
	if (keysym == KEY_A)
		game->player.move_left = 1;
	if (keysym == KEY_S)
		game->player.move_down = 1;
	if (keysym == KEY_D)
		game->player.move_right = 1;
	if (keysym == KEY_LEFT)
		game->player.rotate_left = 1;
	if (keysym == KEY_RIGHT)
		game->player.rotate_right = 1;
	if (keysym == KEY_ESC)
		close_window(game);
	return (0);
}

int	key_release_handling(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		game->player.move_up = 0;
	if (keysym == KEY_A)
		game->player.move_left = 0;
	if (keysym == KEY_S)
		game->player.move_down = 0;
	if (keysym == KEY_D)
		game->player.move_right = 0;
	if (keysym == KEY_LEFT)
		game->player.rotate_left = 0;
	if (keysym == KEY_RIGHT)
		game->player.rotate_right = 0;
	return (0);
}

int	close_window(t_game *game)
{
	free_mlx(game);
	exit(EXIT_SUCCESS);
	return (0);
}
