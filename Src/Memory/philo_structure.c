/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:44:59 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/24 18:07:31 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

void	data_n_time_memory_allocation(t_data **data)
{
	*data = malloc(sizeof(t_data));
	(*data)->time = malloc(sizeof(t_time));
}
