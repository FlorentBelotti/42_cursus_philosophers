/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:42:28 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/24 17:54:00 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	get_args_value(int ac, char **av, t_data *data)
{
	data->time->philo_nb = ft_atoi(av[1]);
	data->time->time_to_die = ft_atoi(av[2]);
	data->time->time_to_eat = ft_atoi(av[3]);
	data->time->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->time->meals_limits = ft_atoi(&av[5][1]);
	else
		data->time->meals_limits = -1;
}
