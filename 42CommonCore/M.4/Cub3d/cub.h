/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 02:56:17 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/31 15:57:05 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "Libft/libft.h"

# define WIDTH 1280
# define HEIGHT 720
# define TILE_SIZE 64
# define FOV 60
# define MAX_MAP_LINES 1000

# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_LEFT XK_Left
# define KEY_RIGHT XK_Right
# define KEY_ESC XK_Escape

enum			e_wall
{
	NO_WALL,
	SO_WALL,
	WE_WALL,
	EA_WALL
};

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_texture
{
	t_img		img;
	char		*path;
}				t_texture;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
	char		start_dir;
}				t_player;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			draw_start;
	int			draw_end;
	int			line_height;
	int			start_unclamped;
	double		wall_x;
}				t_ray;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			floor_color;
	int			ceiling_color;
}				t_map;

typedef struct s_game
{
	void		*mlx_connection;
	void		*window;
	t_img		screen;
	t_map		map;
	t_player	player;
	t_texture	textures[4];
	t_ray		*rays;
}				t_game;

// utils
void			ft_putstr_fd(char *str, int fd);
void			*ft_memset(void *ptr, int replace, size_t len);
void			free_game(t_game *game);

// errors
void			parse_error(t_game *game, char *msg);

// parsing
void			parse_file(char *path, t_game *game);
int				is_map_line(char *line);
void			dispatch_line(char *line, t_game *game);
void			parse_texture(char *str, t_texture *tex, t_game *game);
void			parse_color(char *str, int *color_out, t_game *game);
void			check_all_identifiers_set(t_game *game);
void			map_filler(int fd, char *first_line, t_game *game);
void			normalize_map(t_game *game);
void			validate_map(t_game *game);
void			check_map_closed(t_game *game);
void			init_player_direction(t_game *game);
void			free_split(char **parts);

// init utils
void			ft_putstr_fd(char *str, int fd);
void			*ft_memset(void *par, int replace, size_t len);

// clean up
void			free_mlx(t_game *game);

// init
int				init_mlx(t_game *game);
int				init_player(t_game *game);
int				init_texture(t_game *game);
int				init_game(t_game *game, char *);

// event
void			even_handling(t_game *game);
int				key_handling(int keysym, t_game *game);
int				key_release_handling(int keysym, t_game *game);
int				close_window(t_game *game);

// movement
int				is_wall(t_game *game, double x, double y);
void			move_player(t_game *game, double dx, double dy);
void			rotate_player(t_game *game, double angle);

// DDA & color
void			cast_ray(t_game *game, int x);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				get_texture_color(t_img *texture, int tex_x, int tex_y);
void			draw_column(t_game *game, int x, t_ray *ray);

// render
void			compute_wall_slice(t_ray *ray, int screen_height);
int				render_frame(t_game *game);

#endif