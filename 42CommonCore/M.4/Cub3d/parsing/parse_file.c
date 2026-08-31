/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:49:39 by hadmessa          #+#    #+#             */
/*   Updated: 2026/08/31 21:30:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_file(char *path, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		parse_error(game, "cannot open file");
	line = get_next_line(fd);
	while (line && !is_map_line(line))
	{
		dispatch_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		parse_error(game, "missing map");
			// fichier fini sans jamais voir de map
	check_all_identifiers_set(game);
	map_filler(fd, line, game);
	normalize_map(game);
	validate_map(game);
	close(fd);
}
