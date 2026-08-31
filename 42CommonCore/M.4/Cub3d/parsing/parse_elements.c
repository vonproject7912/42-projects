/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:49:42 by hadmessa          #+#    #+#             */
/*   Updated: 2026/08/31 20:08:53 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


static int  xpm_extension(char *path)
{
    int len;

    len = ft_strlen(path);
    if (len < 4)
        return (0);
    return (!ft_strncmp(path + len - 4, ".xpm", 4));
}

static int is_blank_line(char *line)
{
    int i;
    i = 0;
    while(line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r')
        i++;
    return(line[i] == '\0');
}

void parse_texture(char *str, t_texture *tex, t_game *game)
{
    int len;

    while (*str == ' ' || *str == '\t')
        str++;
    if(*str == '\0')
        parse_error(game, "missing texture path");
    if(tex->path)
        parse_error(game, "duplicates textures have been found");
    len = ft_strlen(str);//tt ca pr checker et enlever le \n
    if(len > 0 && str[len - 1] == '\n')
        len --;
    tex->path = ft_substr(str, 0, len);
    if(!tex->path)
        parse_error(game, "texture failure");
    if (!xpm_extension(tex->path))
        parse_error(game, "texture file must have .xpm extension");
}

void    dispatch_line(char *line, t_game *game)
{
    int i;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (!ft_strncmp(line, "NO", 2) && (line[2] == ' ' || line[2] == '\t'))
        parse_texture(line + 2, &game->textures[NO_WALL], game);
    else if (!ft_strncmp(line, "SO", 2) && (line[2] == ' ' || line[2] == '\t'))
        parse_texture(line + 2, &game->textures[SO_WALL], game);
    else if (!ft_strncmp(line, "WE", 2) && (line[2] == ' ' || line[2] == '\t'))
        parse_texture(line + 2, &game->textures[WE_WALL], game);
    else if (!ft_strncmp(line, "EA", 2) && (line[2] == ' ' || line[2] == '\t'))
        parse_texture(line + 2, &game->textures[EA_WALL], game);
    else if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
        parse_color(line + 1, &game->map.floor_color, game);
    else if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
        parse_color(line + 1, &game->map.ceiling_color, game);
    else if (!is_blank_line(line))
        parse_error(game, "identifier error/malformed line");
}

void    check_all_identifiers_set(t_game *game)
{
    if (!game->textures[NO_WALL].path)
        parse_error(game, "Missing north texture (NO)");
    if (!game->textures[SO_WALL].path)
        parse_error(game, "Missing south texture (SO)");
    if (!game->textures[EA_WALL].path)
        parse_error(game, "Missing east texture (EA)");
    if (!game->textures[WE_WALL].path)
        parse_error(game, "Missing west texture (WE)");
    if (game->map.floor_color == -1)
        parse_error(game, "missing floor color (F)");
    if (game->map.ceiling_color == -1)
        parse_error(game, "Ceiling color missing (C)");
}
