/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:56:56 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/28 16:29:10 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_num(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	argv_to_int(t_data *data, char **argv, int argc)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_num(argv[i]))
			return (1);
		i++;
	}
	data->n_philo = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	if (data->die < 60 || data->eat < 60 || data->sleep < 60
		|| data->n_philo > 200 || data->n_philo < 1)
		return (printf("Error:\nTry higher numbers / less philos!"));
	init_philos(data);
	free(data->philo);
	return (0);
}
