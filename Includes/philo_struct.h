/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:03:57 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/23 18:41:29 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <pthread.h>

typedef pthread_mutex_t t_mtx;

typedef struct s_time
{
	int	philo_nb;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	meals_limits;
	int	start_time;
	int	simulation_state;
}	t_time;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
} t_fork;

typedef struct s_philo
{
	int	philo_id;

	int			meals_nb;
	int			last_meal;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
} t_philo;

typedef struct s_data
{
	struct s_time	*time;
	struct s_philo	*philo;
	struct s_fork	*fork;
}	t_data;

#endif
