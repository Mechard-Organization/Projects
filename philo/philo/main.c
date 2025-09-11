/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:34:09 by mechard           #+#    #+#             */
/*   Updated: 2025/02/06 10:13:08 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	constructor(t_principal *principal)
{
	principal->philos = malloc(sizeof(t_philo) * principal->nb_philo + 1);
	if (!principal->philos)
		return (1);
	principal->forks = malloc(sizeof(pthread_mutex_t) * principal->nb_philo
			+ 1);
	if (!principal->forks)
		return (free(principal->philos), 1);
	init_program(principal);
	if (init_forks(principal))
		return (1);
	if (init_philos(principal))
		return (free(principal->forks), 1);
	if (thread_create(principal))
		return (1);
	destory_all(NULL, principal);
	return (0);
}

int	check_basic_value(char **argv)
{
	int	i;

	i = 0;
	if (ft_atoll(argv[1]) <= 0 || ft_atoll(argv[1]) > 2147483647)
		(error_msg(2), i++);
	if (ft_atoll(argv[2]) <= 0 || ft_atoll(argv[2]) > 2147483647)
		(error_msg(3), i++);
	if (ft_atoll(argv[3]) <= 0 || ft_atoll(argv[3]) > 2147483647)
		(error_msg(4), i++);
	if (ft_atoll(argv[4]) <= 0 || ft_atoll(argv[4]) > 2147483647)
		(error_msg(5), i++);
	if (argv[5] && (ft_atoll(argv[5]) <= 0 || ft_atoll(argv[5]) > 2147483647))
		(error_msg(6), i++);
	return (i);
}

void	set_basic_value(t_principal *data, char **argv)
{
	data->nb_philo = ft_atoll(argv[1]);
	data->time_die = ft_atoll(argv[2]);
	data->time_eat = ft_atoll(argv[3]);
	data->time_sleep = ft_atoll(argv[4]);
	if (argv[5])
		data->win_eat = ft_atoll(argv[5]);
	else
		data->win_eat = -1;
}

int	main(int argc, char **argv)
{
	t_principal	principal;

	if (argc != 5 && argc != 6)
		return (error_msg(0), 1);
	if (parse_error(argv))
		return (error_msg(1), 1);
	if (check_basic_value(argv))
		return (1);
	set_basic_value(&principal, argv);
	if (constructor(&principal))
		return (1);
	return (0);
}
