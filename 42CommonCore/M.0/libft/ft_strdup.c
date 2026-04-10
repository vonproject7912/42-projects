/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:32:27 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:21:26 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// regular strdup
char	*ft_strdup(const char *str)
{
	int		i;
	size_t	len;
	char	*dest;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
