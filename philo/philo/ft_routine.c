/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:02:35 by mechard           #+#    #+#             */
/*   Updated: 2025/02/06 09:50:02 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thinking(t_philo *philo)
{
	message(THINK, philo, philo->id);
	if (philo->num_of_philos % 2 == 1)
	{
		if (((philo->time_to_eat * 2) - philo->time_to_sleep) > 0)
			ft_usleep((philo->time_to_eat * 2) - philo->time_to_sleep);
	}
	else if ((philo->time_to_eat - philo->time_to_sleep) > 0)
		ft_usleep(philo->time_to_eat - philo->time_to_sleep);
}

void	ft_sleeping(t_philo *philo)
{
	message(SLEEP, philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	forkchose(t_philo *philo, int i)
{
	if ((philo->id + i) % 2)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
}

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (philo->num_times_to_eat != -1
		&& philo->meals_eaten >= philo->num_times_to_eat)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return ;
	}
	pthread_mutex_unlock(philo->meal_lock);
	forkchose(philo, 0);
	message(FORK, philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		if (philo->id % 2)
			pthread_mutex_unlock(philo->r_fork);
		else
			pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	forkchose(philo, 1);
	ft_eating_two(philo);
}
