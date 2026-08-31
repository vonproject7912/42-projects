/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:49:47 by hadmessa          #+#    #+#             */
/*   Updated: 2026/08/31 20:29:54 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int max_width(char **grid)
{
    int i;
    int len;
    int max;

    i = 0;
    max = 0;
    while(grid[i])
    {
        len = ft_strlen(grid[i]);
        if(len > max)
            max = len;
        i++;
    }
    return(max);
}

static char *padding_shortline(char *line, int width)
{
    char *padded;
    int len;
    int j;

    len = ft_strlen(line);
    padded = malloc(sizeof(char) * (width + 1));
    if(!padded)
        return NULL;
    j = 0;
    while(j < len)
    {
        padded[j] = line[j];
        j++;
    }
    while(j < width)
        padded[j++] = ' ';
    padded[width] = '\0';
    free(line);
    return(padded);
}

void normalize_map(t_game *game)
{
    int i;
    int width;
    width = max_width(game->map.grid);
    game->map.width = width;
    i = 0;
    while(game->map.grid[i])
    {
        if((int)ft_strlen(game->map.grid[i]) < width)
        {
            game->map.grid[i] = padding_shortline(game->map.grid[i], width);
            if(!game->map.grid[i])
                parse_error(game, "Error during normalization :<");
        }
        i++;
    }

}
