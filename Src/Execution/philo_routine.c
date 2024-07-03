/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:11:08 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/04 01:54:22 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->table->simulation_state == 1)
	{
		philo_is_taking_a_fork(philo);
		philo_is_eating(philo);
		philo_is_dropping_a_fork(philo);
		philo_is_sleeping(philo);
		philo_is_thinking(philo);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->table->simulation_state == 1)
	{
		handle_mutex(&(philo)->table->meals_mutex, LOCK);
		handle_mutex(&(philo)->table->death_mutex, LOCK);
		if (is_philosopher_dead(philo) == 1)
			return (NULL);
		handle_mutex(&(philo)->table->death_mutex, UNLOCK);
		if (philo->table->meals_limits != -1)
			is_philosopher_full(philo);
		handle_mutex(&(philo)->table->meals_mutex, UNLOCK);
		if (are_all_philosophers_full(philo) == 1)
		{
			handle_mutex(&(philo)->table->state_mutex, LOCK);
			philo->table->simulation_state = 0;
			handle_mutex(&(philo)->table->state_mutex, UNLOCK);
			return (NULL);
		}
	}
	return (NULL);
}
