/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 10:28:12 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/31 21:18:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// turn prep wall dist into line_height, a drawing start and end
void	compute_wall_slice(t_ray *ray, int screen_height)
{
	// we calculate the wall height on screen:
	// Perspective Projection: Distance is inversely proportional to height.
	// closer walls (small perp_wall_dist) -> taller line_height.
	// farther walls (large perp_wall_dist) -> shorter line_height.
	ray->line_height = (int)screen_height / ray->perp_wall_dist;
	// we calculate the start of the wall:
	// Center the wall slice vertically on the screen:
	// Start at mid-screen (screen_height/ 2) and move up by half the line height.
	ray->draw_start = -ray->line_height / 2 + screen_height / 2;
	// clamp to top of screen (0) to prevent drawing outside window memory.
	ray->start_unclamped = ray->draw_start;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	// start at mid-screen and move down by half the line lenght
	ray->draw_end = ray->line_height / 2 + screen_height / 2;
	// clamp to bottom of screen (screen_height - 1) to prevent overflow/crashes
	if (ray->draw_end >= screen_height)
		ray->draw_end = screen_height - 1;
}

int	render_frame(t_game *game)
{
	int		x;
	double	dx;
	double	dy;

	x = 0;
	// get the movemement
	dx = game->player.dir_x * game->player.move_speed;
	dy = game->player.dir_y * game->player.move_speed;
	// right rotation making
	if (game->player.rotate_right)
		rotate_player(game, game->player.rot_speed);
	// left rotation making
	if (game->player.rotate_left)
		rotate_player(game, -game->player.rot_speed);
	// MOVE FORWARD along the direction vector (+dx, +dy)
	if (game->player.move_up)
		move_player(game, dx, dy);
	// MOVE BACKWARD opposite to direction vector (-dx, -dy)
	if (game->player.move_down)
		move_player(game, -dx, -dy);
	// MOVE RIGHT perp. vector relative to forward direction (dy, -dx)
	if (game->player.move_right)
		move_player(game, -dy, dx);
	// MOVE LEFT perp. vector opposite to right strafe (dy, -dx)
	if (game->player.move_left)
		move_player(game, dy, -dx);
	while (x < WIDTH)
	{
		// calculate the ray position
		cast_ray(game, x);
		// direction compute_wall_slice(game->rays, HEIGHT);
		compute_wall_slice(game->rays, HEIGHT);
		// calculate the wall distance
		draw_column(game, x, game->rays); // render a column
		x++;
	}
	// push the result to the screen
	mlx_put_image_to_window(game->mlx_connection, game->window,
		game->screen.img_ptr, 0, 0);
	return (0);
}
