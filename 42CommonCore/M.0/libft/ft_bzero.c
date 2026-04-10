/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 00:29:40 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:16:11 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// replace len characters in a string by a '\0'
void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*tmp_str;

	i = 0;
	tmp_str = (char *)str;
	while (i < n)
	{
		tmp_str[i] = 0;
		i++;
	}
}

/* For example:
The string: "I'm tired"; For len = 4;
In memory you’ll get = “    tired”
But since printf stops when there is a ‘\0’,
=> It won’t print anything
*/