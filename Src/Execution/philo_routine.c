/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:11:08 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/02 01:26:27 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void *philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->philo_state == 1)
	{
		philo_is_thinking(philo);
		philo_is_taking_a_fork(philo);
		philo_is_eating(philo);
		philo_is_dropping_a_fork(philo);
		philo_is_sleeping(philo);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (philo->table->simulation_state == 1)
	{
		i = 0;
		while (i < philo->table->philo_nb)
		{
			handle_mutex(&(philo)->table->death_mutex, LOCK);
			if ((get_timestamp() - philo[i].last_meal) > philo->table->time_to_die)
			{
				philo[i].philo_state = 0;
				handle_mutex(&(philo)->table->print_mutex, LOCK);
				printf("\033[1;31m%ld %d %s\033[0m\n", get_timestamp(), philo->philo_id, "has died");
				handle_mutex(&(philo)->table->print_mutex, UNLOCK);
				handle_mutex(&(philo)->table->death_mutex, UNLOCK);
				return (NULL);
			}
			handle_mutex(&(philo)->table->death_mutex, UNLOCK);
			i++;
		}
	}
	return (NULL);
}
