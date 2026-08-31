/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 01:03:19 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/31 01:24:03 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*dup_str(const char *s)
{
	char	*out;
	int		i;

	out = malloc(strlen(s) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

static void	fill_map(t_game *game)
{
	static char	*rows[] = {
		"1111111111",
		"1000000001",
		"1000110001",
		"1000000001",
		"1000000001",
		"1111111111",
		NULL
	};
	int			i;

	i = 0;
	while (rows[i])
		i++;
	game->map.height = i;
	game->map.width = (int)strlen(rows[0]);
	game->map.grid = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (rows[i])
	{
		game->map.grid[i] = dup_str(rows[i]);
		i++;
	}
	game->map.grid[i] = NULL;
}

static void	fill_colors_and_textures(t_game *game)
{
	game->map.floor_color = 0x000000;
	game->map.ceiling_color = 0x000000;
	game->textures[NO_WALL].path = dup_str("textures/wall_1.xpm");
	game->textures[SO_WALL].path = dup_str("textures/wall_2.xpm");
	game->textures[WE_WALL].path = dup_str("textures/wall_3.xpm");
	game->textures[EA_WALL].path = dup_str("textures/wall_4.xpm");
}

static void	fill_player(t_game *game)
{
	game->player.pos_x = 2.5;
	game->player.pos_y = 2.5;
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
}

// only symbol main.c actually calls — everything else in the "parsing"
// section of cub.h stays undefined on purpose, since nothing references
// it yet. Swap this file out (and drop it from the Makefile) once the
// real parser is in.
void	parse_file(char *path, t_game *game)
{
	(void)path;
	fill_map(game);
	fill_colors_and_textures(game);
	fill_player(game);
}
