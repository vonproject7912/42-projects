/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pollock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:23:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:52:24 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	main(void)
{
	int		x;
	int		y;
	void	*mlx_window;
	void	*mlx_connection;

	y = 0;
	x = 0;
	srand(time(NULL));
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, 900, 700, "My window <3");
	while (y < 500)
	{
		x = 0;
		while (x < 700)
		{
			mlx_pixel_put(mlx_connection, mlx_window, 100 + x, 100 + y, rand()
				% 0x1000000);
			x++;
		}
		y++;
	}
	mlx_string_put(mlx_connection, mlx_window, 800, 645, rand() % 0x1000000,
		"My polloc <3");
	mlx_loop(mlx_connection);
}

// srand(time(NULL)); actually makes sure that the rand() function is actually random