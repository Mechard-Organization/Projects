/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:45:04 by mechard@stu       #+#    #+#             */
/*   Updated: 2025/02/01 17:59:16 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_principal *principal, int i)
{
	principal->philos[i].time_to_die = principal->time_die;
	principal->philos[i].time_to_eat = principal->time_eat;
	principal->philos[i].time_to_sleep = principal->time_sleep;
	principal->philos[i].num_of_philos = principal->nb_philo;
	principal->philos[i].num_times_to_eat = principal->win_eat;
}

int	init_philos(t_principal *principal)
{
	int	i;

	i = -1;
	while (++i < principal->nb_philo)
	{
		principal->philos[i].id = i + 1;
		(init_input(principal, i), principal->philos[i].meals_eaten = 0);
		principal->philos[i].start_time = get_current_time();
		principal->philos[i].last_meal = get_current_time();
		principal->philos[i].write_lock = &(principal->write_lock);
		principal->philos[i].dead_lock = &(principal->dead_lock);
		principal->philos[i].meal_lock = &(principal->meal_lock);
		principal->philos[i].dead = &(principal->dead_flag);
		principal->philos[i].l_fork = &(principal->forks[i]);
		if (i == 0)
			principal->philos[i].r_fork = \
&(principal->forks[principal->philos[i].num_of_philos - 1]);
		else
			principal->philos[i].r_fork = &(principal->forks[i - 1]);
	}
	return (0);
}

int	init_forks(t_principal *principal)
{
	int	i;

	i = -1;
	while (++i < principal->nb_philo)
		pthread_mutex_init(&(principal->forks[i]), NULL);
	return (0);
}

void	init_program(t_principal *principal)
{
	principal->dead_flag = 0;
	pthread_mutex_init(&(principal->write_lock), NULL);
	pthread_mutex_init(&(principal->dead_lock), NULL);
	pthread_mutex_init(&(principal->meal_lock), NULL);
}
