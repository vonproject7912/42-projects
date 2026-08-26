/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:09:05 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:03:34 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// simple clean up at the end function
void	clean_up(t_file *folder)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&folder->print_mutex);
	pthread_mutex_destroy(&folder->stop_mutex);
	while (i < folder->num_philos)
	{
		pthread_mutex_destroy(&folder->forks[i]);
		pthread_mutex_destroy(&folder->philosophers[i].meal_mutex);
		i++;
	}
	free(folder->forks);
	free(folder->philosophers);
}

int	main(int ac, char *av[])
{
	t_file	folder;

	if ((ac == 5) || (ac == 6))
	{
		if (parsing_philo(ac, av))
			error_fct("Wrong input");
		data_init(ac, av, &folder);
		start_simulation(&folder);
		clean_up(&folder);
	}
	else
		error_fct("Not the right number of arguments");
	return (0);
}
