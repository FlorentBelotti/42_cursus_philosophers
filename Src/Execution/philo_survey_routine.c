/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_survey_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:24:47 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/04 17:30:59 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	meals_monitoring(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->philo_nb)
	{
		if (philo->full == 1)
			i++;
		else
			break ;
	}
	if (i == philo->table->philo_nb)
	{
		handle_mutex(&(philo)->table->state_mutex, LOCK);
		philo->table->simulation_state = 0;
		handle_mutex(&(philo)->table->state_mutex, UNLOCK);
		print_end(philo, FULL);
		return ;
	}
}

void	is_philosopher_dead(t_philo *philo)
{
	int		i;
	long	last_meal;

	i = 0;
	while (i < philo->table->philo_nb)
	{
		handle_mutex(&(philo)->table->meals_mutex, LOCK);
		last_meal = get_timestamp() - philo[i].last_meal;
		handle_mutex(&(philo)->table->meals_mutex, UNLOCK);
		if (last_meal > philo->table->time_to_die)
		{
			handle_mutex(&(philo)->table->death_mutex, LOCK);
			handle_mutex(&(philo)->table->state_mutex, LOCK);
			philo->table->simulation_state = 0;
			handle_mutex(&(philo)->table->state_mutex, UNLOCK);
			print_end(&philo[i], DEAD);
			handle_mutex(&(philo)->table->death_mutex, UNLOCK);
			return ;
		}
		i++;
	}
}
