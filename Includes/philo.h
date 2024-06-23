/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:03:52 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/23 18:41:58 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./philo_struct.h"
# include "../42_cursus_libft/Includes/libft.h"

#include <pthread.h>
#include <sys/time.h>

void	parse_data(int ac, char **av, t_data *data);

#endif
