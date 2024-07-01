/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:34:06 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/01 18:21:06 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void ft_usleep(int milliseconds)
{
	long start_time;

	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < milliseconds)
		usleep(100);
}

long get_timestamp(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void print_status(t_data *data, char *status)
{
	long timestamp;

	timestamp = get_timestamp();
	handle_mutex(&(data)->print_mutex, LOCK);
	if (data->table->simulation_state == -1)
		printf("%ld %d %s\n", timestamp, data->philo->philo_id, status);
	handle_mutex(&(data)->print_mutex, UNLOCK);
}
