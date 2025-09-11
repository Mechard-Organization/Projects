/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:53:26 by mechard@stu       #+#    #+#             */
/*   Updated: 2025/02/04 08:07:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destory_all(char *str, t_principal *principal)
{
	int	i;

	if (str)
		(write(2, str, ft_strlen(str)), write(2, "\n", 1));
	pthread_mutex_destroy(&(principal->write_lock));
	pthread_mutex_destroy(&(principal->meal_lock));
	pthread_mutex_destroy(&(principal->dead_lock));
	i = -1;
	while (++i < principal->philos[0].num_of_philos)
		pthread_mutex_destroy(&(principal->forks[i]));
	free(principal->philos);
	free(principal->forks);
}

void	ft_eating_two(t_philo *philo)
{
	message(FORK, philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	message(EAT, philo, philo->id);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
