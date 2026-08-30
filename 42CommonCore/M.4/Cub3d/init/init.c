/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 08:49:35 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/31 00:16:16 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// mlx connection
int	init_mlx(t_game *game)
{
	// init the sizes
	game->screen.width = WIDTH;
	game->screen.height = HEIGHT;
	// init the mlx connection to the x server
	game->mlx_connection = mlx_init();
	if (game->mlx_connection == NULL) // small check
		return (1);
	// create the window
	game->window = mlx_new_window(game->mlx_connection, WIDTH, HEIGHT, "wtf");
	if (!game->window) // failed window creation
		return (1);
	// Screen / image creation
	game->screen.img_ptr = mlx_new_image(game->mlx_connection, WIDTH, HEIGHT);
	if (game->screen.img_ptr == NULL)
		return (1);
	// get the screen address
	game->screen.addr = mlx_get_data_addr(game->mlx_connection,
			&game->screen.bits_per_pixel, &game->screen.line_length,
			&game->screen.endian);
	return (0);
}

// init player
int	init_player(t_game *game)
{
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.03;
	game->player.move_up = 0;
	game->player.move_down = 0;
	game->player.move_right = 0;
	game->player.move_left = 0;
	game->player.rotate_right = 0;
	game->player.rotate_left = 0;
	game->rays = malloc(sizeof(t_ray));
	if (!game->rays)
		return (1); 
	return (0);
}

// init texture
int	init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		// Convert the xmp file into an image
		game->textures[i].img.img_ptr = mlx_xpm_file_to_image(game->mlx_connection,
				game->textures[i].path, &game->textures[i].img.width,
				&game->textures[i].img.height);
		if (!game->textures[i].img.img_ptr)
			return (1);
		// get the adress to the first pixel
		game->textures[i].img.addr = mlx_get_data_addr(game->textures[i].img.img_ptr,
				&game->textures[i].img.bits_per_pixel,
				&game->textures[i].img.line_length,
				&game->textures[i].img.endian);
		i++;
	}
	return (0);
}

int	init_game(t_game *game, char *map)
{
	// init mlx
	if (init_mlx(game))
	{
		ft_putstr_fd("Mlx creation failed\n", 2);
		free_mlx(game);
		return (1);
	}
	// init player
	if (init_player(game))
	{
		ft_putstr_fd("Player init failed\n", 2);
		free_mlx(game);
		return (1);
	}
	// init texture
	if (init_texture(game))
	{
		ft_putstr_fd("Texture init failed\n", 2);
		free_mlx(game);
		return (1);
	}
	// event handling
	return (0);
}
