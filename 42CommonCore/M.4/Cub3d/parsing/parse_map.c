/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:49:37 by hadmessa          #+#    #+#             */
/*   Updated: 2026/08/31 20:30:12 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int is_map_line(char *line)
{
    int i;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (!ft_strncmp(line + i, "NO", 2) || !ft_strncmp(line + i, "SO", 2)
        || !ft_strncmp(line + i, "WE", 2) || !ft_strncmp(line + i, "EA", 2))
        return (0);
    if ((line[i] == 'F' || line[i] == 'C')
        && (line[i + 1] == ' ' || line[i + 1] == '\t'))
        return (0);
    return (line[i] == '0' || line[i] == '1' || line[i] == 'N' 
        || line[i] == 'S' || line[i] == 'E' || line[i] == 'W');
}

static char *dup_no_nl(char *line)
{
    int len;

    len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        len--;
    return (ft_substr(line, 0, len));
}

void    map_filler(int fd, char *first_line, t_game *game)
{
    char **lines;
    char *line;
    int count;

    lines = malloc(sizeof(char *) * MAX_MAP_LINES);
    if(!lines)
        parse_error(game, "malloc fail");
    count = 0;
    line = first_line;
    while(line != NULL)
    {
        if(count >= MAX_MAP_LINES - 1)
            parse_error(game, "Map too large !");
        lines[count ++] = dup_no_nl(line);
        free(line);
        line = get_next_line(fd);
    }
    lines[count] = NULL;
    game->map.grid = lines;
    game->map.height = count;
}
