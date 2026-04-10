/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 09:23:25 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:08:58 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	check_if_balanced(char *str)
{
	int	i;
	int	open;
	int	closed;

	i = 0;
	open = 0;
	closed = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				closed++;
		}
		i++;
	}
	return (open + closed);
}

void	my_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	balance_fix(int fixed, int position, int issues, char *str)
{
	int		i;
	char	tmp;

	i = position;
	if (fixed == issues && !check_if_balanced(str))
	{
		my_putstr(str);
		write(1, "\n", 1);
		return ;
	}
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
		{
			tmp = str[i];
			str[i] = ' ';
			balance_fix(fixed + 1, i + 1, issues, str);
			str[i] = tmp;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	issues;

	if (ac == 2)
	{
		issues = check_if_balanced(av[1]);
		balance_fix(0, 0, issues, av[1]);
		return (0);
	}
	else
		return (1);
}
