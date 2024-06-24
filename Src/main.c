/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:27:49 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/24 18:06:30 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

static void	print_time(t_data *data)
{
	printf("philo_nb : %d\n", data->time->philo_nb);
	printf("time_to_die : %d\n", data->time->time_to_die);
	printf("time_to_eat : %d\n", data->time->time_to_eat);
	printf("time_to_sleep : %d\n", data->time->time_to_sleep);
	printf("meals_limits : %d\n", data->time->meals_limits);
}

static void	init_philosophers(int ac, char **av, t_data **data)
{
	data_n_time_memory_allocation(data);
	get_args_value(ac, av, *data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (manage_error(ac, av) == 1)
		return (1);
	init_philosophers(ac, av, &data);
	print_time(data);
}
