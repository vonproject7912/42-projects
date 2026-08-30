/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 10:40:23 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/30 13:30:42 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	// check if in the right range
	if (map_x < 0 || map_x >= game->map.width)
		return (1);
	if (map_y < 0 || map_y >= game->map.height)
		return (1);
	// check for a wall
	if (game->map.grid[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

void	move_player(t_game *game, double dx, double dy)
{
	if (!is_wall(game, game->player.pos_x + dx, game->player.pos_y))
		game->player.pos_x += dx;
	if (!is_wall(game, game->player.pos_x, game->player.pos_y + dy))
		game->player.pos_y += dy;
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y
		* sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y
		* cos(angle);
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y
		* cos(angle);
}
