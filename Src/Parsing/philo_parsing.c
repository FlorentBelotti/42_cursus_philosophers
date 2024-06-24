/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:27:34 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/24 16:04:34 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

static int	check_last_arg(char *av, t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av);
	if (av[i] != '[' || av[len - 1] != ']')
	{
		printf("Philosophers: error: invalid format for meals limit\n");
		parsing_memory_liberation(data);
	}
	i = 1;
	while (av[i] && i < len - 1)
	{
		if (ft_isdigit(av[i]))
			i++;
		else
		{
			printf("Philosophers: error: non-numeric value detected\n");
			parsing_memory_liberation(data);
		}
	}
	return (0);
}

static int	check_av_value(char *av, t_data *data)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			i++;
		else
		{
			printf("Philosophers: error: non-numeric value detected\n");
			parsing_memory_liberation(data);
		}
	}
	return (0);
}

static void	get_data(int ac, char **av, t_data *data)
{
	if (check_av_value(av[1], data) == 0)
		data->time->philo_nb = ft_atoi(av[1], data);
	if (check_av_value(av[2], data) == 0)
		data->time->time_to_die = ft_atoi(av[2], data);
	if (check_av_value(av[3], data) == 0)
		data->time->time_to_eat = ft_atoi(av[3], data);
	if (check_av_value(av[4], data) == 0)
		data->time->time_to_sleep = ft_atoi(av[4], data);
	if (ac == 6)
	{
		if (check_last_arg(av[5], data) == 0)
			data->time->meals_limits = ft_atoi(&av[5][1], data);
	}
	else
		data->time->meals_limits = -1;
}

void	parse_data(int ac, char **av, t_data *data)
{
	if (ac < 4 || ac > 6)
	{
		printf("Philosophers: error: invalid number of arguments\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	data->time = malloc(sizeof(t_time));
	get_data(ac, av, data);
}
