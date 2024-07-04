/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:11:08 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/04 13:52:15 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		state;

	philo = (t_philo *)arg;
	state = philo->table->simulation_state;
	while (state == 1)
	{
		philo_is_taking_a_fork(philo);
		philo_is_eating(philo);
		philo_is_dropping_a_fork(philo);
		philo_is_sleeping(philo);
		philo_is_thinking(philo);
		handle_mutex(&(philo)->table->state_mutex, LOCK);
		state = philo->table->simulation_state;
		handle_mutex(&(philo)->table->state_mutex, UNLOCK);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philo;
	int		state;

	philo = (t_philo *)arg;
	state = philo->table->simulation_state;
	while (state == 1)
	{
		is_philosopher_dead(philo);
		if (philo->table->meals_limits != -1)
			meals_monitoring(philo);
		handle_mutex(&(philo)->table->state_mutex, LOCK);
		state = philo->table->simulation_state;
		handle_mutex(&(philo)->table->state_mutex, UNLOCK);
		//ft_usleep(100);
	}
	return (NULL);
}
