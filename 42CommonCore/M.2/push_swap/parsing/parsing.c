/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:10:33 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:58:36 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// join all my arguments and space separate them
char	*join_arg(int ac, char *av[])
{
	int		i;
	char	*str;
	char	*no_leaks;

	i = 1;
	// init an empty string
	str = ft_strdup("");
	while (i < ac)
	{
		// save the adress to free
		no_leaks = str;
		// join the arguments
		str = ft_strjoin(str, av[i]);
		// free the argument
		free(no_leaks);
		// add a space bar in-between each
		if (i < ac - 1)
		{
			// save the current string
			no_leaks = str;
			// join a space
			str = ft_strjoin(str, " ");
			// free the old string
			free(no_leaks);
		}
		i++;
	}
	return (str);
}

// check if we only have digits
int	are_digits(char *str)
{
	int	i;

	i = 0;
	// sign pass
	if (str[i] == '+' || str[i] == '-')
		i++;
	// empty check
	if (!str[i])
		return (1);
	// actual digit check
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

// check for duplicates
int	dups(char *target, char **tab, int index)
{
	int	i;

	i = 1;
	while (tab[index + i])
	{
		// current tab[i] against the whole tab
		if (!ft_strcmp(target, tab[index + i]))
			return (1);
		i++;
	}
	return (0);
}

// join my arguments, split them and return the result
char	**prep_stack(int ac, char *av[])
{
	char	*str;
	char	**tab;

	str = join_arg(ac, av);
	if (!str)
		return (NULL);
	tab = ft_split(str, ' ');
	if (!tab)
		return (NULL);
	free(str);
	return (tab);
}

// Parse my arguments
t_list	*parsing(char **tab)
{
	int		i;
	long	nbr;
	int		size;
	int		*final_tab;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	size = count_tab(tab);
	final_tab = malloc(sizeof(int) * size);
	if (!final_tab)
		return (NULL);
	while (tab[i])
	{
		// validate input format and uniqueness
		if (are_digits(tab[i]) || dups(tab[i], tab, i))
			return (error_msg(), free_tab(tab), free(final_tab), NULL);
		// turn into a long int
		nbr = atol(tab[i]);
		// range check
		if (is_range(nbr))
			return (error_msg(), free_tab(tab), free(final_tab), NULL);
		final_tab[i++] = (int)nbr;
	}
	// fill and return the stack / free everything
	stack_a = stack_fill(final_tab, size);
	free(final_tab);
	free_tab(tab);
	return (stack_a);
}
