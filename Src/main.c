/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:27:49 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/23 18:42:30 by fbelotti         ###   ########.fr       */
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
}
