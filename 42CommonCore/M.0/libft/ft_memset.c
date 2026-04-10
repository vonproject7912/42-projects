/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:35:38 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:17:50 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It fills the first len bytes of memory block str with the value replace,
// then returns the original pointer str.
void	*ft_memset(void *str, int replace, size_t len)
{
	unsigned char	*tmp_str;

	tmp_str = (unsigned char *)str;
	while (len > 0)
	{
		*(tmp_str++) = (unsigned char)replace;
		len--;
	}
	return (str);
}

/* tmp_str is just a pointer to the same memory as str — so writing to *tmp_str
directly modifies the original. tmp_str is only needed because you can't do pointer
arithmetic on a void. */