/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:48:54 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:03:22 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// clean up function in case during init
void	clean_exit(t_file *folder, char *error_mess)
{
	int	i;

	// if there are forks
	if (folder->forks)
	{
		i = 0;
		while (i < folder->num_philos)
		{
			pthread_mutex_destroy(&folder->forks[i]);
			i++;
		}
		free(folder->forks);
	}
	// if there are philosophers
	if (folder->philosophers)
	{
		i = 0;
		while (i < folder->num_philos)
		{
			pthread_mutex_destroy(&folder->philosophers[i].meal_mutex);
			i++;
		}
		free(folder->philosophers);
	}
	// and print the error message
	print_str(error_mess);
	exit(1);
}

// initialize in my general folder all my input
void	data_init(int ac, char *av[], t_file *folder)
{
	folder->num_philos = my_atol(av[1]);
	folder->time_to_die = my_atol(av[2]);
	folder->time_to_eat = my_atol(av[3]);
	folder->time_to_sleep = my_atol(av[4]);
	if (ac == 6)
		folder->max_meals = my_atol(av[5]);
	else
		folder->max_meals = -1;
	folder->forks = NULL;
	folder->philosophers = NULL;
	fork_init(folder);
	philo_init(folder);
}

// Create my forks
void	fork_init(t_file *folder)
{
	int	i;

	i = 0;
	folder->forks = malloc(sizeof(pthread_mutex_t) * folder->num_philos);
	if (!folder->forks)
		clean_exit(folder, "Forks malloc failed");
	while (i < folder->num_philos)
	{
		if (pthread_mutex_init(&folder->forks[i], NULL))
			clean_exit(folder, "Fork init failed");
		i++;
	}
}

// initalize my philsopher with data
void	philo_init(t_file *folder)
{
	int	i;

	i = 0;
	folder->philosophers = malloc(sizeof(t_philo) * folder->num_philos);
	if (!folder->philosophers)
		clean_exit(folder, "Philosophers malloc failed");
	while (i < folder->num_philos)
	{
		folder->philosophers[i].id = i + 1;
		folder->philosophers[i].meal_eaten = 0;
		folder->philosophers[i].left_fork = &folder->forks[i];
		folder->philosophers[i].right_fork = &folder->forks[(i + 1)
			% folder->num_philos];
		if (pthread_mutex_init(&folder->philosophers[i].meal_mutex, NULL))
			clean_exit(folder, "Mutex init failed");
		folder->philosophers[i].folder = folder;
		i++;
	}
}
