/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_survey_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:24:47 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/04 01:44:13 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

int	are_all_philosophers_full(t_philo *philo)
{
	int	i;
	int	full_count;

	full_count = 0;
	i = 0;
	while (i < philo->table->philo_nb)
	{
		if (philo[i].full == 1)
			full_count++;
		i++;
	}
	if (full_count == philo->table->philo_nb)
	{
		handle_mutex(&(philo)->table->state_mutex, LOCK);
		philo->table->simulation_state = 0;
		handle_mutex(&(philo)->table->state_mutex, UNLOCK);
		handle_mutex(&(philo)->table->print_mutex, LOCK);
		printf("\033[1;32m%ld \tEND \t%s\033[0m\n", get_timestamp(),
			"all philosophers have eaten");
		handle_mutex(&(philo)->table->print_mutex, UNLOCK);
		return (1);
	}
	return (0);
}

void	is_philosopher_full(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->philo_nb)
	{
		if (philo[i].meals_nb == philo->table->meals_limits)
			philo[i].full = 1;
		i++;
	}
}

int	is_philosopher_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->philo_nb)
	{
		if ((get_timestamp() - philo[i].last_meal) > philo->table->time_to_die)
		{
			handle_mutex(&(philo)->table->state_mutex, LOCK);
			philo->table->simulation_state = 0;
			handle_mutex(&(philo)->table->state_mutex, UNLOCK);
			handle_mutex(&(philo)->table->print_mutex, LOCK);
			printf("\033[1;31m%ld \t%d \t%s\033[0m\n", get_timestamp(),
				philo[i].philo_id, "has died");
			handle_mutex(&(philo)->table->print_mutex, UNLOCK);
			return (1);
		}
		i++;
	}
	return (0);
}
