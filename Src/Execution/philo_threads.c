/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:57:36 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/01 16:33:51 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	ft_usleep(int milliseconds)
{
	long start_time;

	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < milliseconds)
		usleep(100);
}

long	get_timestamp(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_status(t_data *data, char *status)
{
	long	timestamp;

	timestamp = get_timestamp();
	handle_mutex(&(data)->print_mutex, LOCK);
	if (data->time->simulation_state == -1)
		printf("%ld %d %s\n", timestamp, data->philo->philo_id, status);
	handle_mutex(&(data)->print_mutex, UNLOCK);
}

void	philo_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (data->time->simulation_state == -1)
	{
		philo_is_thinking(data);
		philo_is_taking_a_fork(data);
		philo_is_eating(data);
		philo_is_dropping_a_fork(data);
		philo_is_sleeping(data);
	}
	return ;
}

void	create_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->time->philo_nb)
	{
		safe_thread_handle(&data->philo[i].thread_id, philo_routine,
			&data->philo[i], CREATE);
		i++;
	}
}
