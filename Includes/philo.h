/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:03:52 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/24 17:22:10 by fbelotti         ###   ########.fr       */
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

void	parse_data(int ac, char **av, t_data *data);

/* Error_utils */

int		ft_isdigit(char c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

/* Errors */

int	manage_error(int ac, char **av);

#endif
