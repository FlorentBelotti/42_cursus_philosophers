/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:12:48 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/01 18:35:02 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void philo_is_thinking(t_data *data)
{
	print_status(data, "is thinking");
}

void philo_is_taking_a_fork(t_data *data)
{
	handle_mutex(&(data)->philo->first_fork->fork, LOCK);
	print_status(data, "has taken a fork");
	handle_mutex(&(data)->philo->second_fork->fork, LOCK);
	print_status(data, "has taken a second fork");
}

void philo_is_eating(t_data *data)
{
	handle_mutex(&(data)->philo->death_mutex, LOCK);
	data->philo->last_meal = get_timestamp();
	print_status(data, "is eating");
	handle_mutex(&(data)->philo->death_mutex, UNLOCK);
	ft_usleep(data->table->time_to_eat);
	handle_mutex(&(data)->meals_mutex, LOCK);
	data->philo->meals_nb++;
	handle_mutex(&(data)->meals_mutex, UNLOCK);
}

void philo_is_dropping_a_fork(t_data *data)
{
	handle_mutex(&(data)->philo->first_fork->fork, UNLOCK);
	handle_mutex(&(data)->philo->second_fork->fork, UNLOCK);
}

void philo_is_sleeping(t_data *data)
{
	print_status(data, "is sleeping");
	ft_usleep(data->table->time_to_sleep);
}
