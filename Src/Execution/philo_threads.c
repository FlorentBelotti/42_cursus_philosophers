/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:57:36 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/26 16:57:55 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	create_all_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->time->philo_nb)
	{
		safe_thread_handle(&data->philo[i].thread_id, simulate_dinner,
			&data->philo[i], CREATE);
		i++;
	}
}
