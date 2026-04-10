/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 03:59:41 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:03:28 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// Set simulation running to 0 and print message
void	philosopher_died(int i, t_file *folder)
{
	pthread_mutex_lock(&folder->stop_mutex);
	folder->simulation_running = 0;
	pthread_mutex_unlock(&folder->stop_mutex);
	pthread_mutex_lock(&folder->print_mutex);
	printf("%lu %d died\n", (get_time() - folder->start_time),
		folder->philosophers[i].id);
	pthread_mutex_unlock(&folder->print_mutex);
}

// Philosopher reached their maximum of meals
void	philosopher_full_fct(t_file *folder)
{
	pthread_mutex_lock(&folder->stop_mutex);
	folder->simulation_running = 0;
	pthread_mutex_unlock(&folder->stop_mutex);
	pthread_mutex_lock(&folder->print_mutex);
	printf("All philosophers are full!\n");
	pthread_mutex_unlock(&folder->print_mutex);
}

// check if simulation running hasn't been set to 1
int	status_check(t_file *folder)
{
	int	status;

	pthread_mutex_lock(&folder->stop_mutex);
	status = (folder->simulation_running);
	pthread_mutex_unlock(&folder->stop_mutex);
	return (status);
}

// check all the ways a philosopher could die
int	full_check(int i, int philosopher_full, t_file *folder)
{
	uint64_t	meal_eaten;
	uint64_t	last_meal_time;
	uint64_t	time_to_die;
	uint64_t	max_meals;

	// take all the values I need into variables
	pthread_mutex_lock(&folder->philosophers[i].meal_mutex);
	meal_eaten = folder->philosophers[i].meal_eaten;
	last_meal_time = folder->philosophers[i].last_meal_time;
	time_to_die = folder->time_to_die;
	max_meals = folder->max_meals;
	pthread_mutex_unlock(&folder->philosophers[i].meal_mutex);
	// check if the last meal has exceed the dying time
	if (get_time() - last_meal_time >= time_to_die)
		return (philosopher_died(i, folder), -1);
	// check if the maximum of meals have been reached
	else if (meal_eaten >= max_meals && max_meals != -1) // unsure w/ -1
		philosopher_full += 1;
	return (philosopher_full);
}

// create the monitor and for each philosopher, check if he is still alive
void	*my_monitor(void *arg)
{
	int		i;
	t_file	*folder;
	int		philosopher_full;

	folder = (t_file *)arg;
	// as long as the simulation running isn't set to 0
	while (status_check(folder) != 0)
	{
		i = 0;
		philosopher_full = 0;
		// check both if a philosopher has died or if one is full
		while (i < folder->num_philos)
		{
			philosopher_full = full_check(i, philosopher_full, folder);
			if (philosopher_full == -1)
				return (NULL);
			i++;
		}
		// check if all philosophers are full
		if (philosopher_full == folder->num_philos)
			return (philosopher_full_fct(folder), NULL);
		usleep(100);
	}
	return (NULL);
}
