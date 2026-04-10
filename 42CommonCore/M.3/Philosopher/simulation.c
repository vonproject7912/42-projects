/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:14:43 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:03:42 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// again a checking function
int	small_check(t_philo *philosopher)
{
	int	res;

	pthread_mutex_lock(&philosopher->folder->stop_mutex);
	res = (philosopher->folder->simulation_running);
	pthread_mutex_unlock(&philosopher->folder->stop_mutex);
	return (res);
}

// case where we have only one philosopher
int	one_philosopher(t_philo *philosopher)
{
	if (philosopher->folder->num_philos == 1)
	{
		if (philosopher->meal_eaten >= philosopher->folder->max_meals
			&& philosopher->folder->max_meals != 0)
			// should've locked this data
			return (1);
		if (small_check(philosopher) == 0)
			return (1);
		// grabs it's left fork
		pthread_mutex_lock(philosopher->left_fork);
		pthread_mutex_lock(&philosopher->folder->print_mutex);
		printf("%lu %d has taken a fork\n", (get_time()
				- philosopher->folder->start_time), philosopher->id);
		pthread_mutex_unlock(&philosopher->folder->print_mutex);
		// sleeps until it dies
		while (small_check(philosopher) != 0)
			usleep(100);
		return (1);
	}
	return (0);
}

// actual routine for each philosopher
void	*my_routine(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	// one philosopher case
	if (one_philosopher(philosopher))
		return (NULL);
	// makes even philosopher wait for odd ones to start
	if ((philosopher->id % 2) == 0)
		usleep(1000);
	while (small_check(philosopher) != 0)
	{
		eating(philosopher);
		if (small_check(philosopher) == 0)
			return (NULL);
		sleeping(philosopher);
		if (small_check(philosopher) == 0)
			return (NULL);
		thinking(philosopher);
		if (small_check(philosopher) == 0)
			return (NULL);
	}
	return (NULL);
}

// create my philosophers, my monitor and init everything
void	start_simulation(t_file *folder)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	// initialize everything
	folder->simulation_running = 1;
	pthread_mutex_init(&folder->print_mutex, NULL);
	pthread_mutex_init(&folder->stop_mutex, NULL);
	while (i < folder->num_philos)
		folder->start_time = get_time();
	folder->philosophers[i++].last_meal_time = get_time();
	i = 0;
	// create the philosopher
	while (i < folder->num_philos)
	{
		if (pthread_create(&folder->philosophers[i].thread_id, NULL, my_routine,
				&folder->philosophers[i]))
			clean_exit(folder, "Thread create failed");
		i++;
	}
	// create my monitor
	if (pthread_create(&monitor_thread, NULL, my_monitor, folder))
		clean_exit(folder, "Monitor creation failed");
	i = 0;
	// wait for my monitor
	pthread_join(monitor_thread, NULL);
	// wait for my philosophers
	while (i < folder->num_philos)
		pthread_join(folder->philosophers[i++].thread_id, NULL);
}
