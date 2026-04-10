/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:37:51 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:20:40 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies len bytes from src to dst, but safely handles overlapping memory
// — if src is before dst it copies backwards to avoid overwriting data before it's copied.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	i = 0;
	if (!dst && !src)
		return (NULL);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	// src is before dst, risk of overlap — copy backwards
	if (tmp_src < tmp_dst)
	{
		while (len-- > 0)
			tmp_dst[len] = tmp_src[len];
	}
	// no overlap risk — copy forwards normally
	else
	{
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	return (dst);
}

/* Imagine src and dst point to regions that share memory:
src:  [A][B][C][D][E]
			↑
dst:       [B][C][D][E][F]
If you copy forwards like ft_memcpy would:

dst[0] = src[0] → overwrites B with A ... but B was also src[1]
Now src[1] is corrupted before you even read it

So copying backwards (from end to start) avoids this — you never overwrite
a byte before you've already copied it.
after:  [A] [A] [B] [C] [D] [E]
*/