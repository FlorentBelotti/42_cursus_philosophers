/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:49:39 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/24 17:22:32 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/philo.h"

static int	check_av_value(char *av)
{
	int		i;
	long	value;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			i++;
		else
		{
			printf("Philosophers: error: non-numeric value detected\n");
			return (1);
		}
	}
	value = ft_atoi(av);
	if (value > INT_MAX || value < INT_MIN)
	{
		printf("Philosophers: error: value out of bound\n");
		return (1);
	}
	return (0);
}

static int	check_last_arg(char *av)
{
	int		i;
	int		len;
	long	value;

	i = 0;
	len = ft_strlen(av);
	if (av[i] != '[' || av[len - 1] != ']')
	{
		printf("Philosophers: error: invalid format for meals limit\n");
		return (1);
	}
	i = 1;
	while (av[i] && i < len - 1)
	{
		if (ft_isdigit(av[i]))
			i++;
		else
		{
			printf("Philosophers: error: non-numeric value detected\n");
			return (1);
		}
	}
	value = ft_atoi(&av[1]);
	if (value > INT_MAX || value < INT_MIN)
	{
		printf("Philosophers: error: value out of bound\n");
		return (1);
	}
	return (0);
}

int	manage_error(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 4 || ac > 6)
	{
		printf("Philosophers: error: invalid number of arguments\n");
		return (1);
	}
	while (av[i])
	{
		if (i == 5)
		{
			if (check_last_arg(av[i]) == 1)
				return (1);
		}
		else
		{
			if (check_av_value(av[i]) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
