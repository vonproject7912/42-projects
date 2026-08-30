/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:11:07 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/30 22:42:57 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// read a 32-bit color from a image texture coordinate
int	get_texture_color(t_img *texture, int tex_x, int tex_y)
{
	char	*pixel;

	// return black if the coordinate fall outside the image
	if (tex_x < 0 || tex_x >= texture->width || tex_y < 0
		|| tex_y >= texture->height)
		return (0);
	// calculate memory offset:
	// (Row Index * Bytes Per Row) + (Column Index * Bytes Per Pixel)
	pixel = texture->addr + (tex_y * texture->line_length + tex_x
			* (texture->bits_per_pixel / 8));
    // Cast pointer to unsigned int* to dereference all 4 color channels 
    // (32 bits) at once
	return (*(unsigned int *)pixel);
}

// determine the wall textures (NO, SO, EA, WE) based on wall and ray orientation
static t_texture	*pick_texture(t_game *game, t_ray *ray)
{
    // vertical grid line (East/West)
	if (ray->side == 0 && ray->ray_dir_x > 0)
    // ray moving Right (+X) -> looking at West face
		return (&game->textures[WE_WALL]);
	if (ray->side == 0)
    // ray moving Left (-X) -> looking at East face
		return (&game->textures[EA_WALL]);
    // horizontal grid line hit (North/South wall face)
	if (ray->ray_dir_y > 0)
    // ray moving Down (+Y) -> looking at North face
		return (&game->textures[NO_WALL]);
    // ray moving Up (-Y) -> looking at South face
	return (&game->textures[SO_WALL]);
}

// calculate the exact x picel column within the 
static int	get_tex_x(t_texture *tex, t_ray *ray)
{
	int	tex_x;

    // scale wall_x (fraction from 0.0 to 1.0) to actual texture pixel width
	tex_x = (int)(ray->wall_x * tex->img.width);
    // flip texture X coordinate horizontally when necessary 
    // so textures aren't mirrored backward
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		tex_x = tex->img.width - tex_x - 1;
	return (tex_x);
}

void	draw_column(t_game *game, int x, t_ray *ray)
{
	t_texture	*tex;
	int			tex_x;
	int			y;
	int			tex_y;
	int			color;

	tex = pick_texture(game, ray);
	tex_x = get_tex_x(tex, ray);
	y = 0;
    // iterate vertically down screen column x
	while (y < HEIGHT)
	{
        // above draw_start -> render floor color
		if (y < ray->draw_start)
			my_mlx_pixel_put(&game->screen, x, y, game->map.ceiling_color);
        // below draw_end -> render floor color
		else if (y > ray->draw_end)
			my_mlx_pixel_put(&game->screen, x, y, game->map.floor_color);
		else
		{
            // inside wall slice -> calculate texture Y coordinate via linear mapping:
            // (Current wall Y distance) / (Total wall line height) * (Texture height)
			tex_y = (int)((y - ray->draw_start) * tex->img.height
					/ (double)ray->line_height);
            // fetch texture pixel color and write to screen frame buffer
			color = get_texture_color(&tex->img, tex_x, tex_y);
			my_mlx_pixel_put(&game->screen, x, y, color);
		}
		y++;
	}
}
