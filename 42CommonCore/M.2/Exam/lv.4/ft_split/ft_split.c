/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:23:53 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:48:56 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	count_words(const char *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}

static int	word_len(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	i = 0;
	words = count_words(str, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (i < words)
	{
		j = 0;
		while (*str && *str == c)
			str++;
		tab[i] = malloc(sizeof(char) * word_len(str, c) + 1);
		if (!tab[i])
		{
			free_tab(tab) return (NULL);
		}
		while (*str && *str != c)
			tab[i][j++] = *str++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	main(void)
{
	size_t	i;
	size_t	c;
	char	*str;
	char	**tab;

	c = ' ';
	i = 0;
	str = "      ";
	tab = ft_split(str, c);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free_tab(tab);
	return (0);
}
