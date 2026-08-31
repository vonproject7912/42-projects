/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhadra <mokhadra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:36:12 by mokhadra          #+#    #+#             */
/*   Updated: 2025/11/14 15:18:37 by mokhadra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	sep(char sep, char c)
{
	if (sep == c)
		return (1);
	return (0);
}

int	count_word(char *str, char set)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] && sep(str[i], set))
			i++;
		if (str[i] && !sep(str[i], set))
			c++;
		while (str[i] && !sep(str[i], set))
			i++;
	}
	return (c);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*copy(char *str, int *i, char set)
{
	int		start;
	int		len;
	int		j;
	char	*mot;

	len = 0;
	j = 0;
	start = *i;
	while (str[*i] && !sep(str[*i], set))
	{
		(*i)++;
		len++;
	}
	mot = malloc(len + 1);
	if (!mot)
		return (NULL);
	while (j < len)
	{
		mot[j] = str[start + j];
		j++;
	}
	mot[j] = '\0';
	return (mot);
}

char	**ft_split(char *str, char set)
{
	int		i;
	int		size;
	char	**tab;
	int		k;

	i = 0;
	k = 0;
	size = count_word(str, set);
	tab = malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] && sep(str[i], set))
			i++;
		if (str[i] && !sep(str[i], set))
		{
			tab[k] = copy(str, &i, set);
			if (!tab[k])
				return (free_tab(tab), NULL);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
