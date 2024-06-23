/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:27:34 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/23 18:43:04 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

static int	check_av_value(char *av)
{
	int	i;

	while (av[i])
	{
		if (ft_isdigit(av[i]))
			i++;
		else
		{
			printf("Philosopher: error: incorrect value\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

static void	get_data(char **av, t_time *time)
{
	if (check_av_value(av[1]) == 0)
		time->philo_nb = ft_atoi(av[1]);
	if (check_av_value(av[2]) == 0)
		time->time_to_die = ft_atoi(av[2]);
	if (check_av_value(av[3]) == 0)
		time->time_to_eat = ft_atoi(av[3]);
	if (check_av_value(av[4]) == 0)
		time->time_to_sleep = ft_atoi(av[4]);
}

void	parse_data(int ac, char **av, t_data *data)
{
	(void)ac;
	data->time = malloc(sizeof(t_time));
	get_data(av, data->time);
	/*if (ac == 6)
		get_meals_limits(av[6]);
	else
		data->time->meals_limits = -1;*/
}
