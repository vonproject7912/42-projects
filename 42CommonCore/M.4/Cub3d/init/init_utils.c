/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:47:48 by vonpr             #+#    #+#             */
/*   Updated: 2026/08/27 10:11:05 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ft_putstr_fd(char *str, int fd)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	*ft_memset(void *game, int replace, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)game;
	while (len > 0)
	{
		*ptr = (unsigned char)replace;
		ptr++;
		len--;
	}
	return (game);
}
