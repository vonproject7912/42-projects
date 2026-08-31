/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:49:44 by hadmessa          #+#    #+#             */
/*   Updated: 2026/08/31 21:30:50 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	valid_rgb(int number)
{
	return (number >= 0 && number <= 255);
}

void	parse_color(char *str, int *color_out, t_game *game)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	while (*str == ' ' || *str == '\t')
		str++;
	parts = ft_split(str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		parse_error(game, "invalid color format, expected R,G,B");
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	if (!valid_rgb(r) || !valid_rgb(g) || !valid_rgb(b))
		parse_error(game, "RGB values must be between 0 and 255");
	*color_out = (r << 16) | (g << 8) | b;
		// remplace l'ancien remplissage séparé : combine les 3 valeurs en un seul entier packé au format 0xRRGGBB,
	// directement utilisable par mlx_pixel_put côté exec
	free_split(parts);
}
