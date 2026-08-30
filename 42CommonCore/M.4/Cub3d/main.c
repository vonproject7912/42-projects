/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 09:45:41 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/31 00:24:10 by vonpr            ###   ########.fr       */
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
	parse_file(av[1], &game);
	if (init_game(&game, av[1])) // init struct
		return (1);
	// render function
	even_handling(&game);
	mlx_loop(game.mlx_connection); // loop window
	return (0);
}
