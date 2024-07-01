/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:03:52 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/02 00:18:00 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# include "./philo_struct.h"

# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

/* Parsing */

void	get_args_values(int ac, char **av, t_data *data);
void	get_philosophers_data(t_data **data);

/* Errors */

int		manage_error(int ac, char **av);
int		ft_isdigit(char c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

/* Memory */

int		data_n_time_memory_allocation(t_data **data);
int		philo_n_forks_memory_allocation(t_data **data);
void	free_allocated_memory(t_data *data);
void	init_mutex(t_data **data);
int		handle_mutex(t_mtx *mutex, t_opcode opcode);

/* Execution */

void	create_philo_threads(t_data *data);
void	philo_is_thinking(t_philo *philo);
void	philo_is_taking_a_fork(t_philo *philo);
void	philo_is_eating(t_philo *philo);
void	philo_is_dropping_a_fork(t_philo *philo);
void	philo_is_sleeping(t_philo *philo);
long	get_timestamp(void);
void	safe_thread_handle(pthread_t *thread, void *(*function)(void *), void *data, t_opcode opcode);
void	print_status(t_philo *philo, char *status);
void	ft_usleep(int milliseconds);
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);
void	create_monitor_thread(t_data *data);

#endif
