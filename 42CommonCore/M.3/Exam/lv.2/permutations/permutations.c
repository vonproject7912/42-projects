/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 09:21:05 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:08:40 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "permutations.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// pre-sorting that has been asked:
// "The solutions must be given in alphabetical order"
void	sorting(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

// actual permutation and backtracking
void	permutation(int position, int len, char *placed, char *res, char *str)
{
	int	i;

	i = 0;
	// if we've reached the end print
	if (position == len)
	{
		ft_putstr(res);
		write(1, "\n", 1);
		return ;
	}
	// otherwise
	while (i < len)
	{
		// choose an unused letter
		if (placed[i] == 0)
		{
			// mark the letter as used
			placed[i] = 1;
			// add the letter to the permutation
			res[position] = str[i];
			// call permutation to build the rest of the line
			permutation(position + 1, len, placed, res, str);
			// cancel the choice to make another permutation
			placed[i] = 0;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int		len;
	char	*res;
	char	*placed;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		res = malloc(sizeof(char) * len + 1);
		// we need placed to be 0 initialized for later use (like for union/inter tab)
		placed = calloc(len, sizeof(int));
		if (!res || !placed)
			return (1);
		sorting(av[1]);
		permutation(0, len, placed, res, av[1]);
		free(res);
		free(placed);
		return (0);
	}
	else
		return (1);
}
