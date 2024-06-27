/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_memory_allocation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:44:59 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/26 16:04:27 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

int	data_n_time_memory_allocation(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!(*data))
	{
		free_allocated_memory(*data);
		return (1);
	}
	(*data)->time = malloc(sizeof(t_time));
	if (!(*data)->time)
	{
		free_allocated_memory(*data);
		return (1);
	}
	return (0);
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

int	philo_n_forks_memory_allocation(t_data **data)
{
	int	i;

	i = 0;
	(*data)->philo = malloc(sizeof(t_philo) * (*data)->time->philo_nb);
	if (!(*data)->philo)
	{
		free_allocated_memory(*data);
		return (1);
	}
	(*data)->fork = malloc(sizeof(t_fork) * (*data)->time->philo_nb);
	if (!(*data)->fork)
	{
		free_allocated_memory(*data);
		return (1);
	}
	while (i < (*data)->time->philo_nb)
	{
		if (handle_mutex(&(*data)->fork[i].fork, INIT) == 1)
		{
			free_allocated_memory(*data);
			return (1);
		}
		(*data)->fork[i].fork_id = i;
		i++;
	}
	return (0);
}
