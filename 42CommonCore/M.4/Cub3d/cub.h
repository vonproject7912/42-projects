/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 08:51:08 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/28 10:44:51 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# include <math.h>
# include <fcntl.h>

// Window
# define WIDTH   1280
# define HEIGHT  720
# define TILE_SIZE   64
# define FOV         60

// Keycodes
# define KEY_W      13
# define KEY_A      0
# define KEY_S      1
# define KEY_D      2
# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_ESC    53

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	t_img	img;
	char	*path;
}	t_texture;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;			
	int		draw_start;
	int		draw_end;
	int		line_height;
	double	wall_x;
}	t_ray;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	char	*no_tex_path;
	char	*so_tex_path;
	char	*ea_tex_path;
	char	*we_tex_path;
	int		floor_color;
	int		ceiling_color;
}	t_map;

typedef struct s_game
{
	void		*mlx_connection;
	void		*window;
	t_img		screen;
	t_map		map;
	t_player	player;
	t_texture	textures[4];
	t_ray		*rays;
}	t_game;



#endif