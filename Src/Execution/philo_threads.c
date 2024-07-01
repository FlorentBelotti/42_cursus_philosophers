/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:57:36 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/01 18:20:55 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void *philo_routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	while (data->table->simulation_state == -1)
	{
		philo_is_thinking(data);
		philo_is_taking_a_fork(data);
		philo_is_eating(data);
		philo_is_dropping_a_fork(data);
		philo_is_sleeping(data);
	}
	return (NULL);
}

void safe_thread_handle(pthread_t *thread, void *(*function)(void *), void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		pthread_create(thread, NULL, function, data);
	else if (JOIN == opcode)
		pthread_join(*thread, NULL);
	else if (DETACH == opcode)
		pthread_detach(*thread);
}

void create_philo_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->table->philo_nb)
	{
		safe_thread_handle(&data->philo[i].thread_id, philo_routine(data),
						   &data->philo[i], CREATE);
		i++;
	}
}

int handle_mutex(t_mtx *mutex, t_opcode opcode)
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
