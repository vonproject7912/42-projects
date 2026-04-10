/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:39:52 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:17:33 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It compares the first n bytes of str with the character c,
// and returns a pointer to its first occurrence, or NULL if not found.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*str;

	uc = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
