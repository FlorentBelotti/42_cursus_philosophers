/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:27:49 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/26 16:44:34 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

static void	print_time(t_data *data)
{
	int	i = -1;

	printf("\n----- TIME -----\n\n");
	printf("philo_nb : %d\n", data->time->philo_nb);
	printf("time_to_die : %d\n", data->time->time_to_die);
	printf("time_to_eat : %d\n", data->time->time_to_eat);
	printf("time_to_sleep : %d\n", data->time->time_to_sleep);
	printf("meals_limits : %d\n\n", data->time->meals_limits);
	printf("\n----- MUTEX -----\n\n");
	while (++i < data->time->philo_nb)
		printf("fork_id : %d\n", data->fork[i].fork_id);
	while (++i < data->time->philo_nb)
	{
		printf("\n---- PHILO N°%d ----\n\n", i);
		printf("philo_id : %d\n", data->philo[i].philo_id);
		printf("meals_nb : %d\n", data->philo[i].meals_nb);
		printf("full : %d\n", data->philo[i].full);
		printf("left_fork_id : %d\n", data->philo[i].first_fork->fork_id);
		printf("right_fork_id : %d\n", data->philo[i].second_fork->fork_id);
		printf("thread_id : %d\n\n", data->philo[i].thread_id);
	}
}

static int	start_dinner(t_data *data)
{
	if (check_table_n_guests(data) == 1)
		return (1);
	return (0);
}

static int	init_philosophers(int ac, char **av, t_data **data)
{
	if (data_n_time_memory_allocation(data) == 1)
		return (1);
	get_args_values(ac, av, *data);
	if (philo_n_forks_memory_allocation(data) == 1)
		return (1);
	get_philosophers_data(data);
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
	print_time(data);
	free_allocated_memory(data);
	return (0);
}
