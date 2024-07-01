/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:13:50 by fbelotti          #+#    #+#             */
/*   Updated: 2024/07/01 12:13:48 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

int	check_table_n_guests(t_data *data)
{
	if (data->time->meals_limits == 0)
	{
		printf("Philosopher: dinner: no food to eat! Everyone is dead...\n");
		free_allocated_memory(data);
		return (1);
	}
	if (data->time->philo_nb == 0)
	{
		printf("Philosopher: dinner: No one came! you have no friend...\n");
		free_allocated_memory(data);
		return (1);
	}
	return (0);
}
