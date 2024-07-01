/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:03:57 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/01 15:40:24 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <pthread.h>

typedef pthread_mutex_t t_mtx;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

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
	int			full;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_mtx		death_mutex;
	t_mtx		meals_mutex;
	t_mtx		print_mutex;
} t_philo;

typedef struct s_data
{
	struct s_time	*time;
	struct s_philo	*philo;
	struct s_fork	*fork;
	t_mtx			death_mutex;
	t_mtx			meals_mutex;
	t_mtx			print_mutex;
}	t_data;

#endif
