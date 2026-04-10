/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 03:58:45 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:03:31 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// regular error function
void	error_fct(char *error_mess)
{
	print_str(error_mess);
	exit(1);
}

// not so great simple parsing...
int	parsing_philo(int ac, char *av[])
{
	int	arg;
	int	digit;

	arg = 1;
	digit = 0;
	while (arg < ac)
	{
		digit = 0;
		while (av[arg][digit])
		{
			if (!(av[arg][digit] >= '0' && av[arg][digit] <= '9'))
				return (print_str("Input isn't the right type\n"), 1);
			digit++;
		}
		if (my_atol(av[arg]) > INT_MAX || my_atol(av[arg]) <= 0)
			return (print_str("One parameter is empty or overflows\n"), 1);
		arg++;
	}
	return (0);
}
