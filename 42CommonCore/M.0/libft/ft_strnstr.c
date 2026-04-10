/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:26:12 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:21:51 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Searches for to_find inside str, but only within the first len characters
// — returns a pointer to the match, or NULL if not found.
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	// empty to_find, return str immediately
	if (to_find[0] == '\0')
		return ((char *)str);
	// loop through str within len limit
	while (str[i] && (i < len))
	{
		j = 0;
		// use i to go through the chaine and j to to go through the to_find
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			// full match found
			// return pointer to match start
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	// no match found
	return (NULL);
}
