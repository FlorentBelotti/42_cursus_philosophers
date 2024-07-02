/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:12:48 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/02 16:43:02 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void philo_is_thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void philo_is_taking_a_fork(t_philo *philo)
{
	handle_mutex(&(philo)->first_fork->fork, LOCK);
	print_status(philo, "has taken a fork");
	handle_mutex(&(philo)->second_fork->fork, LOCK);
	print_status(philo, "has taken a fork");
}

void philo_is_eating(t_philo *philo)
{
	print_status(philo, "is eating");
	ft_usleep(philo->table->time_to_eat);
	philo->last_meal = get_timestamp();
	philo->meals_nb++;
}

void philo_is_dropping_a_fork(t_philo *philo)
{
	handle_mutex(&(philo)->first_fork->fork, UNLOCK);
	handle_mutex(&(philo)->second_fork->fork, UNLOCK);
}

void philo_is_sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
}
