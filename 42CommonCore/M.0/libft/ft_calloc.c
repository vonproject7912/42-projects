/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 00:29:53 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:16:15 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// malloc a string full of 0s
void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			len;
	unsigned char	*safe;

	i = 0;
	len = count * size;
	safe = malloc(len);
	if (!safe)
		return (NULL);
	while (i < len)
		safe[i++] = 0;
	return (safe);
}

/* To test it out:
Safe is the "appartement" rented
and we define the owner in the main.
*/