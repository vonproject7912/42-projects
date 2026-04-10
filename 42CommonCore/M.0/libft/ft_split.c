/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 05:33:16 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:18:12 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// get the ammount of words
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

// get the lenght of a word
static int	word_len(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

// clean up function
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

// main function
char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	i = 0;
	words = count_words(str, c);
	// allocate the tab
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	// for each words
	while (i < words)
	{
		j = 0;
		// skip spaces
		while (*str && *str == c)
			str++;
		// allocate the lenght of the word
		tab[i] = malloc(sizeof(char) * word_len(str, c) + 1);
		if (!tab[i])
			return (free_tab(tab), NULL);
		// fill the tab with the word
		while (*str && *str != c)
			tab[i][j++] = *str++;
		// finish the 'line'
		tab[i][j] = '\0';
		i++;
	}
	// last tab must be NULL
	tab[i] = NULL;
	return (tab);
}
