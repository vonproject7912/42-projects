/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:49:27 by hadmessa          #+#    #+#             */
/*   Updated: 2026/08/31 21:31:03 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E');
}

static void	check_chars(t_game *game)
{
	int		y;
	int		x;
	int		spawn_count;
	char	c;

	spawn_count = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			c = game->map.grid[y][x];
			if (!is_valid_char(c))
				parse_error(game, "invalid character in map");
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				spawn_count++;
				game->player.start_dir = c;
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
			}
			x++;
		}
		y++;
	}
	if (spawn_count == 0)
		parse_error(game, "no player spawn found");
	if (spawn_count > 1)
		parse_error(game, "multiple player spawns found");
}

void	validate_map(t_game *game)
{
	check_chars(game);
	check_map_closed(game);
	init_player_direction(game);
}
