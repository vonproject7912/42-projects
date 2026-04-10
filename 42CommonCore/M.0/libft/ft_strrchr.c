/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:31:14 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:21:53 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// same as strchr but reversed
char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	x;

	i = 0;
	x = (unsigned char)c;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)x)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

// use of a unsigned char for paco tests