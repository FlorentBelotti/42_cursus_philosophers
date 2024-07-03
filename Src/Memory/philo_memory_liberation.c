/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_memory_liberation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:46:40 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/04 00:31:12 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	free_allocated_memory(t_data *data)
{
	int	i;

	i = 0;
	if (data->fork)
	{
		while (i < data->table->philo_nb)
		{
			pthread_mutex_destroy(&(data->fork[i].fork));
			i++;
		}
		free(data->fork);
	}
	if (data->philo)
		free(data->philo);
	if (data->table)
		free(data->table);
	free(data);
}
