/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 03:58:10 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 16:03:36 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <limits.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_file	t_file;

typedef struct s_philo
{
	int					id;
	uint64_t			meal_eaten;
	uint64_t			last_meal_time;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		meal_mutex;
	pthread_t			thread_id;
	t_file				*folder;
}						t_philo;

typedef struct s_file
{
	int					num_philos;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	uint64_t			max_meals;
	pthread_mutex_t		*forks;
	t_philo				*philosophers;
	uint64_t			start_time;
	int					simulation_running;
	pthread_mutex_t		stop_mutex;
	pthread_mutex_t		print_mutex;
}						t_file;

/*          UTILS        */
void					print_str(char *str);
long					my_atol(const char *str);
uint64_t				get_time(void);
void					precise_sleep(uint64_t time_in_ms);

/*         PARSINGGG       */
void					error_fct(char *error_mess);
int						parsing_philo(int ac, char *av[]);

/*         DATA INIT       */
void					clean_exit(t_file *folder, char *error_mess);
void					data_init(int ac, char *av[], t_file *folder);
void					fork_init(t_file *folder);
void					philo_init(t_file *folder);

/*         ROUTINES        */
int						taking_forks(t_philo *philosopher);
void					eating(t_philo *philosopher);
void					sleeping(t_philo *philosopher);
void					thinking(t_philo *philosopher);

/*         SIMULATION       */
int						small_check(t_philo *philosopher);
int						one_philosopher(t_philo *philosopher);
void					*my_routine(void *arg);
void					start_simulation(t_file *folder);

/*           MONITOR         */
void					philosopher_died(int i, t_file *folder);
void					philosopher_full_fct(t_file *folder);
int						status_check(t_file *folder);
int						full_check(int i, int philosopher_full, t_file *folder);
void					*my_monitor(void *arg);

/*      CLEAN UP HEHE     */
void					clean_up(t_file *folder);

#endif