/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:27:49 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/24 14:05:24 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	parse_data(ac, av, data);
	printf("philo_nb : %d\n", data->time->philo_nb);
	printf("time_to_die : %d\n", data->time->time_to_die);
	printf("time_to_eat : %d\n", data->time->time_to_eat);
	printf("time_to_sleep : %d\n", data->time->time_to_sleep);
	if (ac == 6)
		printf("meals_limits : %d\n", data->time->meals_limits);
}
