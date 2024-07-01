/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:03:52 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/01 16:30:24 by fbelotti         ###   ########.fr       */
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

int		check_table_n_guests(t_data *data);
void	create_philo_threads(t_data *data);
void	philo_is_thinking(t_data *data);
void	philo_is_taking_a_fork(t_data *data);
void	philo_is_eating(t_data *data);
void	philo_is_dropping_a_fork(t_data *data);
void	philo_is_sleeping(t_data *data);
long	get_timestamp(void);

#endif
