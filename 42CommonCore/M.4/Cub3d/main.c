/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 09:45:41 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/28 09:52:06 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

	if (ac != 2) // argument check
	{
		ft_putstr_fd("Usage: ./cub3D <map.cub>\n", 2);
        return (1);
	}
	if (!parsing(av[1])) // parse check
	{
			ft_putstr_fd("Error: invalid file extension\n", 2);
    		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game)); // init data
	if (init_game(&game, av[1])) // init struct
		return (1);
	mlx_loop(game.mlx_connection); // loop window
	// render function
	return (0);
}
