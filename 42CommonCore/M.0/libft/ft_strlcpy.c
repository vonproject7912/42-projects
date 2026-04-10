/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:31:59 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:21:38 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// regular strlcpy but you copy and just return len
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/* Example:
str = "I'm tired" out put will be "I'm"
(3 chars + null terminator, fits exactly in 4 bytes)
minus one for the nul terminator
*/