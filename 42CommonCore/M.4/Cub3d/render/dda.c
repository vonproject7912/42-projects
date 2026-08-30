/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 13:34:11 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/30 20:23:20 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_ray(t_game *game, int x)
{
    // init the camera
	game->rays->camera_x = 2 * x / (double)WIDTH - 1;
    // find the ray's direction on x
	game->rays->ray_dir_x = game->player.dir_x + game->player.plane_x
		* game->rays->camera_x;
    // find the ray's direction on y
	game->rays->ray_dir_y = game->player.dir_y + game->player.plane_y
		* game->rays->camera_x;
    // init map_x being the int of pos_x (float)
	game->rays->map_x = (int)game->player.pos_x;
	game->rays->map_y = (int)game->player.pos_y;
    // side_dist is how far to the next grid line and delta dist the steps we take
	game->rays->delta_dist_x = fabs(1 / game->rays->ray_dir_x);
	game->rays->delta_dist_y = fabs(1 / game->rays->ray_dir_y);
}

static void	init_step(t_game *game)
{
	// if (with the camera scale) the rays points to the left of the screen
	if (game->rays->ray_dir_x < 0)
	{
		game->rays->step_x = -1; // meaning the ray is pointing left
		// we get the distance to the next grid line on x
		game->rays->side_dist_x = (game->player.pos_x - game->rays->map_x)
			* game->rays->delta_dist_x;
	}
	// otherwise points to the right
	else 
	{
		game->rays->step_x = 1; // meaning the ray is pointing right
		// we get the distance to the next grid line on x
		game->rays->side_dist_x = (game->rays->map_x + 1 - game->player.pos_x)
			* game->rays->delta_dist_x; 
		// while map_x give us the left grid line we do + 1 to get the one on the right
	}
	// Same process for y
	if (game->rays->ray_dir_y < 0)
	{
		game->rays->step_y = -1;
		game->rays->side_dist_y = (game->player.pos_y - game->rays->map_y)
			* game->rays->delta_dist_y;
	}
	else
	{
		game->rays->step_y = 1;
		game->rays->side_dist_y = (game->rays->map_y + 1 - game->player.pos_y)
			* game->rays->delta_dist_y;
	}
}

static void	dda_loop(t_game *game)
{
	while (1)
	{
		// we compare which one is closer to a grid line
		if (game->rays->side_dist_x < game->rays->side_dist_y)
		{
			// we add delta_dist to side_dist on x
			game->rays->side_dist_x += game->rays->delta_dist_x;
			game->rays->map_x += game->rays->step_x; // move forward
			game->rays->side = 0; // means we crossed a vertical line (either E/W)
		}
		else
		{
			// we add delta_dist to side_dist on y
			game->rays->side_dist_y += game->rays->delta_dist_y;
			game->rays->map_y += game->rays->step_y; // move forward
			game->rays->side = 1; // means we crossed a horizontal line (either N/S)
		}
		// check for any value going over the map
		if (game->rays->map_y < 0 || game->rays->map_y >= game->map.height
			|| game->rays->map_x < 0 || game->rays->map_x >= game->map.width)
			break ;
		// check if there is a wall
		if (game->map.grid[game->rays->map_y][game->rays->map_x] == '1')
			break ;
	}
}

static void	compute_hit(t_game *game)
{
	// CALCULATE PERPENDICULAR WALL DISTANCE
	if (game->rays->side == 0) // the ray hit a vertical wall grid (so E/W)
	// Formula: (Grid_Pos - Player_Pos + Offset_Correction) / Ray_Direction_X
	// Step offset adjustment: 
        // - If ray is moving right (step_x == 1): offset is 0
        // - If ray is moving left (step_x == -1): offset is 1
		game->rays->perp_wall_dist = (game->rays->map_x - game->player.pos_x
				+ (1 - game->rays->step_x) / 2.0) / game->rays->ray_dir_x;
	else // the ray hit a horizontal wall grid (so N/S)
		game->rays->perp_wall_dist = (game->rays->map_y - game->player.pos_y
				+ (1 - game->rays->step_y) / 2.0) / game->rays->ray_dir_y;
	// CALCULATE THE EXACT IMPACT POINT ON THE WALL
	if (game->rays->side == 0) // find the y impact position
		game->rays->wall_x = game->player.pos_y + game->rays->perp_wall_dist
			* game->rays->ray_dir_y;
	else // find the x impact position
		game->rays->wall_x = game->player.pos_x + game->rays->perp_wall_dist
			* game->rays->ray_dir_x;
	// we keep the fractional part / the position within that tile face to know
	// which vertical strip of the texture image to print
	game->rays->wall_x -= floor(game->rays->wall_x);
}

void	cast_ray(t_game *game, int x)
{
	init_ray(game, x);
	init_step(game);
	dda_loop(game);
	compute_hit(game);
}
