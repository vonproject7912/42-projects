/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo <mo@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:52:50 by mokhadra          #+#    #+#             */
/*   Updated: 2026/01/10 18:52:25 by mo               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_g(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	search_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup_g(char *s1)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = malloc((ft_strlen_g(s1) + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	char	*tab;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	tab = malloc((ft_strlen_g(s1) + ft_strlen_g(s2) + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	ptr = tab;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (tab);
}

char	*ft_substr_g(char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen_g(s);
	if (start >= s_len)
		return (ft_strdup_g(""));
	if (len > s_len - start)
		len = s_len - start;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
