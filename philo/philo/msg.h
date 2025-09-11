/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:14:16 by mechard           #+#    #+#             */
/*   Updated: 2025/02/06 10:20:39 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

/*_______________MSGS_ERROR_______________*/

# ifndef ERROR_NB_ARG
#  define ERROR_NB_ARG "Error, wrong number of arguments.\nThe arguments are: \
number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, (optional)[num\
ber_of_times_each_philosopher_must_eat]\n"
# endif

# ifndef ERROR_C_THREAD
#  define ERROR_C_THREAD "Thread creation error"
# endif

# ifndef ERROR_J_THREAD
#  define ERROR_J_THREAD "Thread join error"
# endif

# ifndef ERROR_GTOD
#  define ERROR_GTOD "gettimeofday() error\n"
# endif

# ifndef ERROR_ALPH
#  define ERROR_ALPH "Error, none numeric or negative argument\
 found in parsing\n"
# endif

# ifndef ERROR_0_PHILO
#  define ERROR_0_PHILO "Error, number of philos set to zero or overflow !\n"
# endif

# ifndef ERROR_0_TTD
#  define ERROR_0_TTD "Error, time to die set to zero or overflow !\n"
# endif

# ifndef ERROR_0_TTE
#  define ERROR_0_TTE "Error, time to eat set to zero or overflow !\n"
# endif

# ifndef ERROR_0_TTS
#  define ERROR_0_TTS "Error, time to sleep set to zero or overflow !\n"
# endif

# ifndef ERROR_0_TMD
#  define ERROR_0_TMD "Error, time must die set to zero or overflow !\n"
# endif

/*_______________MSGS_ERROR_______________*/

# ifndef DIE
#  define DIE "died"
# endif

# ifndef SLEEP
#  define SLEEP "is sleeping"
# endif

# ifndef EAT
#  define EAT "is eating"
# endif

# ifndef THINK
#  define THINK "is thinking"
# endif

# ifndef FORK
#  define FORK "has taken a fork"
# endif

#endif