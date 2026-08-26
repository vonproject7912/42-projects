/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 09:10:30 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:03:40 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// taking left and right fork
int	taking_forks(t_philo *philosopher)
{
	// left fork
	pthread_mutex_lock(philosopher->left_fork);
	if (small_check(philosopher) == 0)
	{
		pthread_mutex_unlock(philosopher->left_fork);
		return (1);
	}
	pthread_mutex_lock(&philosopher->folder->print_mutex);
	printf("%lu %d has taken a fork\n", (get_time()
			- philosopher->folder->start_time), philosopher->id);
	pthread_mutex_unlock(&philosopher->folder->print_mutex);
	// right fork
	pthread_mutex_lock(philosopher->right_fork);
	if (small_check(philosopher) == 0)
	{
		pthread_mutex_unlock(philosopher->left_fork);
		pthread_mutex_unlock(philosopher->right_fork);
		return (1);
	}
	pthread_mutex_lock(&philosopher->folder->print_mutex);
	printf("%lu %d has taken a fork\n", (get_time()
			- philosopher->folder->start_time), philosopher->id);
	pthread_mutex_unlock(&philosopher->folder->print_mutex);
	return (0);
}

// calls for forks grabing and eats
void	eating(t_philo *philosopher)
{
	if (philosopher->meal_eaten >= philosopher->folder->max_meals
		&& philosopher->folder->max_meals != 0)
		// should be protected before using those data
		return ;
	if (!small_check(philosopher))
		return ;
	if (taking_forks(philosopher))
		return ;
	pthread_mutex_lock(&philosopher->folder->print_mutex);
	printf("%lu %d is eating\n", (get_time() - philosopher->folder->start_time),
		philosopher->id);
	pthread_mutex_unlock(&philosopher->folder->print_mutex);
	pthread_mutex_lock(&philosopher->meal_mutex);
	philosopher->last_meal_time = get_time();
	philosopher->meal_eaten += 1;
	pthread_mutex_unlock(&philosopher->meal_mutex);
	precise_sleep(philosopher->folder->time_to_eat);
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
}

// as the name implies
void	sleeping(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->folder->print_mutex);
	printf("%lu %d is sleeping\n", (get_time()
			- philosopher->folder->start_time), philosopher->id);
	pthread_mutex_unlock(&philosopher->folder->print_mutex);
	precise_sleep(philosopher->folder->time_to_sleep);
}

// as the name implies
void	thinking(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->folder->print_mutex);
	printf("%lu %d is thinking\n", (get_time()
			- philosopher->folder->start_time), philosopher->id);
	pthread_mutex_unlock(&philosopher->folder->print_mutex);
}
