/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhadra <mokhadra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:37:01 by mokhadra          #+#    #+#             */
/*   Updated: 2025/12/31 16:57:58 by mokhadra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_seen(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	int		len;
	char	*tab;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_seen(s1[start], set))
		start++;
	while (end > start && ft_seen(s1[end], set))
		end--;
	len = end - start + 1;
	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	len = 0;
	while (start <= end)
		tab[len++] = s1[start++];
	tab[len] = '\0';
	return (tab);
}
