/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:34:06 by mechard           #+#    #+#             */
/*   Updated: 2025/02/04 07:52:59 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*________________LIBRARIES_______________*/

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "msg.h"

/*_______________STRUCTURES_______________*/

/*Structure for parse data of philosophers. The last argument is optionnal.
  RTFNV !*/

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct principal
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				win_eat;
}					t_principal;

/*_______________FUNCTIONS________________*/

/*  Function returning a numeric value  */

int					ft_isdigit(int c);
int					parse_error(char **argv);
int					init_forks(t_principal *principal);
int					init_philos(t_principal *principal);
int					thread_create(t_principal *principal);
int					dead_check(t_philo *philo);
int					check_if_all_ate(t_philo *philos);
int					check_if_dead(t_philo *philos);
int					philosopher_dead(t_philo *philo, size_t time_to_die);
int					ft_usleep(size_t microseconds);
int					ft_strlen(char *str);
long long			ft_atoll(const char *str);
size_t				get_current_time(void);

/*  Function returning a void  */

void				error_msg(int code);
void				destory_all(char *str, t_principal *principal);
void				init_program(t_principal *principal);
void				init_input(t_principal *principal, int i);
void				*monitor(void *data);
void				*philo_routine(void *data);
void				ft_eating(t_philo *philo);
void				ft_eating_two(t_philo *philo);
void				ft_sleeping(t_philo *philo);
void				ft_thinking(t_philo *philo);
void				message(char *str, t_philo *philo, int id);

#endif