/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:27:49 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/04 17:28:50 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

static int	check_table_n_guests(t_data *data)
{
	if (data->table->meals_limits == 0)
	{
		printf("Philosopher: dinner: no food to eat! Everyone is dead...\n");
		free_allocated_memory(data);
		return (1);
	}
	if (data->table->philo_nb == 0)
	{
		printf("Philosopher: dinner: No one came! you have no friend...\n");
		free_allocated_memory(data);
		return (1);
	}
	return (0);
}

static int	start_dinner(t_data *data)
{
	if (check_table_n_guests(data) == 1)
		return (1);
	if (data->table->philo_nb == 1)
	{
		data->table->start_time = get_timestamp();
		safe_thread_handle(&data->philo[0].thread_id, lone_philosopher_routine,
			&data->philo[0], CREATE);
		create_monitor_thread(data);
	}
	else
	{
		create_philo_threads(data);
		create_monitor_thread(data);
	}
	return (0);
}

static int	init_philosophers(int ac, char **av, t_data **data)
{
	if (data_n_time_memory_allocation(data) == 1)
		return (1);
	get_args_values(ac, av, *data);
	if (philo_n_forks_memory_allocation(data) == 1)
	{
		free_allocated_memory(*data);
		return (1);
	}
	get_philosophers_data(data);
	init_mutex(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (manage_error(ac, av) == 1)
		return (1);
	if (init_philosophers(ac, av, &data) == 1)
		return (1);
	if (start_dinner(data) == 1)
		return (1);
	free_allocated_memory(data);
	return (0);
}
