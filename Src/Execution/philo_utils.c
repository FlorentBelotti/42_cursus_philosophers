/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:34:06 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/03 19:51:42 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	ft_usleep(int milliseconds)
{
	long	start_time;

	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < milliseconds)
		usleep(100);
}

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_status(t_philo *philo, int statcode)
{
	long	timestamp;

	timestamp = get_timestamp();
	handle_mutex(&(philo)->table->print_mutex, LOCK);
	if (philo->table->simulation_state == 1)
	{
		if (statcode == EATING)
			printf("%ld \t%d \t\033[38;5;226m%s\033[0m\n", timestamp,
				philo->philo_id, "is eating");
		else if (statcode == THINKING)
			printf("%ld \t%d \t\033[38;5;27m%s\033[0m\n", timestamp,
				philo->philo_id, "is thinking");
		else if (statcode == TAKING)
			printf("%ld \t%d \t\033[38;5;208m%s\033[0m\n", timestamp,
				philo->philo_id, "has taken a fork");
		else if (statcode == SLEEPING)
			printf("%ld \t%d \t\033[38;5;201m%s\033[0m\n", timestamp,
				philo->philo_id, "is sleeping");
	}
	handle_mutex(&(philo)->table->print_mutex, UNLOCK);
}
