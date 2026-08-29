/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 09:45:41 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/29 08:49:02 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main (int ac, char **av)
{
	t_game game;

	if (ac != 2) // argument check
	{
		ft_putstr_fd("Usage: ./cub3D <map.cub>\n", 2);
        return (1);
	}
	ft_memset(&game, 0, sizeof(t_game)); // init data
	if (!parsing(av[1])) // parse check
	{
			ft_putstr_fd("Error: invalid file extension\n", 2);
    		return (1);
	}
	if (init_game(&game, av[1])) // init struct
		return (1);
	mlx_loop(game.mlx_connection); // loop window
	// render function
	return (0);
}
