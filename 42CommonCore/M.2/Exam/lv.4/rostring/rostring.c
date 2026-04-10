/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:24:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:40:52 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	rostring(char *str)
{
	int	i;
	int	j;

	i = 0;
	// skip spaces
	while (str[i] && str[i] == ' ' || str[i] == '\t')
		i++;
	j = i;
	// using j as a flag
	while (str[i])
	{
		// skip first word
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		// skip spaces
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		// if there is a letter and right before a space
		while ((str[i] && (str[i] != ' ' && str[i] != '\t')) && (str[i
				- 1] == ' ' || str[i - 1] == '\t'))
		{
			// print the word
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, " ", 1);
			i++;
		}
	}
	// print the flag word
	while (str[j] && (str[j] != ' ' && str[j] != '\t'))
	{
		write(1, &str[j], 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		rostring(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
