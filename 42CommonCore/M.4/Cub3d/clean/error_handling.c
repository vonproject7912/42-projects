/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:50:03 by hadmessa          #+#    #+#             */
/*   Updated: 2026/08/31 20:28:13 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void parse_error(t_game *game, char *msg)
{
    ft_putstr_fd("Error\n", 2);
    if(msg)
    {
        ft_putstr_fd(msg, 2);
        ft_putstr_fd("\n", 2);
    }
    free_game(game);
    exit(1);
}
