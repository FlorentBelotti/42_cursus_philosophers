/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:11:08 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/05 23:46:49 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	*lone_philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_status(&philo[0], TAKING);
	ft_usleep(philo->table->time_to_die);
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		state;

	philo = (t_philo *)arg;
	handle_mutex(&(philo)->table->state_mutex, LOCK);
	state = philo->table->simulation_state;
	handle_mutex(&(philo)->table->state_mutex, UNLOCK);
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
	handle_mutex(&(philo)->table->state_mutex, LOCK);
	state = philo->table->simulation_state;
	handle_mutex(&(philo)->table->state_mutex, UNLOCK);
	while (state == 1)
	{
		is_philosopher_dead(philo);
		if (philo->table->meals_limits != -1)
			meals_monitoring(philo);
		handle_mutex(&(philo)->table->state_mutex, LOCK);
		state = philo->table->simulation_state;
		handle_mutex(&(philo)->table->state_mutex, UNLOCK);
	}
	return (NULL);
}
