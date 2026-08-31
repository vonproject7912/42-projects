/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhadra <mokhadra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:36:57 by mokhadra          #+#    #+#             */
/*   Updated: 2025/11/13 14:45:54 by mokhadra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	a;

	a = (unsigned char)c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == a)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
