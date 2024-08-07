/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:57:36 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/03 19:50:12 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	create_monitor_thread(t_data *data)
{
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	pthread_create(&monitor_thread, NULL, monitor_routine, data->philo);
	pthread_join(monitor_thread, NULL);
	while (i < data->table->philo_nb)
	{
		safe_thread_handle(&data->philo[i].thread_id, philo_routine,
			&data->philo[i], JOIN);
		i++;
	}
}

void	create_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	data->table->start_time = get_timestamp();
	handle_mutex(&(data)->table->death_mutex, LOCK);
	while (i < data->table->philo_nb)
	{
		safe_thread_handle(&data->philo[i].thread_id, philo_routine,
			&data->philo[i], CREATE);
		i++;
	}
	handle_mutex(&(data)->table->death_mutex, UNLOCK);
}

void	safe_thread_handle(pthread_t *thread, void *(*function)(void *),
			void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		pthread_create(thread, NULL, function, data);
	else if (JOIN == opcode)
		pthread_join(*thread, NULL);
	else if (DETACH == opcode)
		pthread_detach(*thread);
}

int	handle_mutex(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		pthread_mutex_lock(mutex);
	else if (UNLOCK == opcode)
		pthread_mutex_unlock(mutex);
	else if (INIT == opcode)
		pthread_mutex_init(mutex, NULL);
	else if (DESTROY == opcode)
		pthread_mutex_destroy(mutex);
	else
	{
		printf("Philosophers: error: wrong opcode\n");
		return (1);
	}
	return (0);
}
