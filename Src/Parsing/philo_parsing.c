/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:42:28 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/26 12:06:26 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	get_args_values(int ac, char **av, t_data *data)
{
	data->time->philo_nb = ft_atoi(av[1]);
	data->time->time_to_die = ft_atoi(av[2]);
	data->time->time_to_eat = ft_atoi(av[3]);
	data->time->time_to_sleep = ft_atoi(av[4]);
	data->time->simulation_state = -1;
	if (ac == 6)
		data->time->meals_limits = ft_atoi(&av[5][1]);
	else
		data->time->meals_limits = -1;
}

void	assign_philosopher_forks(int philo_pos, t_philo *philo, t_data **data)
{
	int	philo_nb;

	philo_nb = (*data)->time->philo_nb;
	philo->second_fork = &(*data)->fork[philo_pos];
	philo->first_fork = &(*data)->fork[(philo_pos + 1) % philo_nb];
	if (philo->philo_id % 2)
	{
		philo->first_fork = &(*data)->fork[philo_pos];
		philo->second_fork = &(*data)->fork[(philo_pos + 1) % philo_nb];
	}
}

void	get_philosophers_data(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->time->philo_nb)
	{
		(*data)->philo[i].meals_nb = 0;
		(*data)->philo[i].philo_id = i;
		(*data)->philo[i].full = -1;
		assign_philosopher_forks(i, &(*data)->philo[i], data);
		i++;
	}
}