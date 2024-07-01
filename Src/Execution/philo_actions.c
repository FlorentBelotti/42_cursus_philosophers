/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:12:48 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/01 22:50:13 by fbelotti         ###   ########.fr       */
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
	print_status(philo, "has taken a second fork");
}

void philo_is_eating(t_philo *philo)
{
	handle_mutex(&(philo)->table->death_mutex, LOCK);
	philo->last_meal = get_timestamp();
	print_status(philo, "is eating");
	handle_mutex(&(philo)->table->death_mutex, UNLOCK);
	ft_usleep(philo->table->time_to_eat);
	handle_mutex(&(philo)->table->meals_mutex, LOCK);
	philo->meals_nb++;
	handle_mutex(&(philo)->table->meals_mutex, UNLOCK);
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
