/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 08:49:35 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/27 10:16:09 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int init_mlx(t_game *game)
{
	// init the mlx connection to the x server
	game->mlx_connection = mlx_init(); 
	if (game->mlx_connection == NULL) // small check
		return (1);
	// create the window
	game->window = mlx_new_window(game->mlx_connection, WIDTH, HEIGHT, "wtf");
	if (!game->window) // failed window creation
	{
		mlx_destroy_display(game->mlx_connection); // detruire la connection
		free(game->mlx_connection); // et la free
		return (1);
	}
	// Screen / image creation
	game->screen.img_ptr = mlx_new_image(game->mlx_connection, WIDTH, HEIGHT);
	if (game->screen.img_ptr == NULL)
	{
		mlx_destroy_window(game->mlx_connection, game->window);
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		return (1);
	}
	// get the screen address
	game->screen.addr = mlx_get_data_addr(game->mlx_connection, 
		&game->screen.bits_per_pixel, &game->screen.line_length, &game->screen.endian);
	return (0);
}

int init_game(t_game *game, char *map)
{
	if (init_mlx(game))
	{
		ft_putstr_fd("Mlx creation failed\n", 2);
		return (1);
	}
	// event handling
	// init player
	// init texture
	// init picture
	return (0);
}

int main (int ac, char **av)
{
	t_game game;

	// if (ac != 2) // argument check
	// {
	// 	ft_putstr_fd("Usage: ./cub3D <map.cub>\n", 2);
    //     return (1);
	// }
	// if (!parsing(av[1])) // parse check
	// {
	// 		ft_putstr_fd("Error: invalid file extension\n", 2);
    // 		return (1);
	// }
	ft_memset(&game, 0, sizeof(t_game)); // init the game
	if (init_game(&game, av[1])) // struct
		return (1);
	mlx_loop(game.mlx_connection); // loop to keep the window open
	// render
	return (0);
}
