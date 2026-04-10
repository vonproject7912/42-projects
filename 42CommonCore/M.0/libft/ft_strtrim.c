/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:54:19 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:21:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns 1 if c is in set, 0 otherwise
static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// Removes all characters found in set from the beginning and end of s1.
char	*ft_strtrim(char const *str, char const *set)
{
	size_t	end;
	size_t	start;

	// if s1 is NULL, return empty string
	if (!str)
		return (ft_strdup(""));
	// if set is NULL, nothing to trim, return s1
	if (!set)
		return (ft_strdup(str));
	start = 0;
	end = ft_strlen(str);
	// move start forward past trimmed chars
	while (is_set(str[start], set))
		start++;
	// string was all trimmed chars
	if (start == end)
		return (ft_strdup(""));
	// move end backward past trimmed chars
	while (is_set(str[end - 1], set))
		end--;
	// return the middle part
	return (ft_substr(str, start, end - start));
}
