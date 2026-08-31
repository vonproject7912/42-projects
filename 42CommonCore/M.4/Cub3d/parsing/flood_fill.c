/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:49:51 by hadmessa          #+#    #+#             */
/*   Updated: 2026/08/31 21:30:43 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_outside_map(t_game *game, int y, int x)
{
	return (y < 0 || y >= game->map.height || x < 0 || x >= game->map.width);
}

static void	flood_fill(t_game *game, char **beenthere, int y, int x)
{
	if (is_outside_map(game, y, x))
		parse_error(game, "Map is not closed");
	if (game->map.grid[y][x] == '1')
		return ;
	if (beenthere[y][x] == 'V')
		return ;
	beenthere[y][x] = 'V';
	flood_fill(game, beenthere, y - 1, x);
	flood_fill(game, beenthere, y + 1, x);
	flood_fill(game, beenthere, y, x - 1);
	flood_fill(game, beenthere, y, x + 1);
}

static char	**create_visited_grid(t_game *game)
{
	int	i;

	char **beenthere; // relire quand meme
	beenthere = malloc(sizeof(char *) * (game->map.height + 1));
	if (!beenthere)
		parse_error(game, "malloc failed");
	i = 0;
	while (i < game->map.height)
	{
		beenthere[i] = malloc(sizeof(char) * game->map.width);
		if (!beenthere[i])
			parse_error(game, "malloc failed");
		ft_memset(beenthere[i], '0', game->map.width);
		i++;
	}
	beenthere[i] = NULL;
	return (beenthere);
}

static void	free_visited_grid(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	check_map_closed(t_game *game)
{
	char	**beenthere;
	int		player_y;
	int		player_x;

	beenthere = create_visited_grid(game);
	player_y = (int)game->player.pos_y;
	player_x = (int)game->player.pos_x;
	flood_fill(game, beenthere, player_y, player_x);
	free_visited_grid(beenthere, game->map.height);
}
