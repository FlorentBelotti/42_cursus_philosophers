/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_memory_allocation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:44:59 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/04 00:43:50 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	init_mutex(t_data **data)
{
	int	i;

	i = 0;
	handle_mutex(&(*data)->table->print_mutex, INIT);
	handle_mutex(&(*data)->table->death_mutex, INIT);
	handle_mutex(&(*data)->table->meals_mutex, INIT);
	handle_mutex(&(*data)->table->state_mutex, INIT);
	while (i < (*data)->table->philo_nb)
	{
		(*data)->philo[i].table = (*data)->table;
		i++;
	}
}

int	data_n_time_memory_allocation(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!(*data))
	{
		free_allocated_memory(*data);
		return (1);
	}
	(*data)->table = malloc(sizeof(t_table));
	if (!(*data)->table)
	{
		free_allocated_memory(*data);
		return (1);
	}
	return (0);
}

int	philo_n_forks_memory_allocation(t_data **data)
{
	int	i;

	i = 0;
	(*data)->philo = malloc(sizeof(t_philo) * (*data)->table->philo_nb);
	if (!(*data)->philo)
		return (1);
	(*data)->fork = malloc(sizeof(t_fork) * (*data)->table->philo_nb);
	if (!(*data)->fork)
		return (1);
	while (i < (*data)->table->philo_nb)
	{
		if (handle_mutex(&(*data)->fork[i].fork, INIT) == 1)
			return (1);
		(*data)->fork[i].fork_id = i;
		i++;
	}
	return (0);
}
