/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_memory_liberation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:46:40 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/26 16:02:03 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	free_allocated_memory(t_data *data)
{
	int	i;

	i = 0;
	if (data->fork)
	{
		while (i < data->time->philo_nb)
		{
			pthread_mutex_destroy(&(data->fork[i].fork));
			i++;
		}
		free(data->fork);
	}
	if (data->philo)
		free(data->philo);
	if (data->time)
		free(data->time);
	free(data);
}
