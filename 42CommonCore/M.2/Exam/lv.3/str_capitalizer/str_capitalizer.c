/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:16:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:39:40 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	str_cap(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i
				- 1] == '\t'))
			str[i] -= 32;
		if (str[0] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	i;

	i = 1;
	if (ac == 1)
		write(1, "\n", 1);
	while (i < ac)
	{
		str_cap(av[i]);
		i++;
	}
	return (0);
}
