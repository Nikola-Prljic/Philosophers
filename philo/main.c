/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:47:47 by nprljic           #+#    #+#             */
/*   Updated: 2023/04/21 09:01:05 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*just_one_philo(void *ptr)
{
	t_philo	*p;

	p = (t_philo *)ptr;
	p->s_time = timestamp();
	printf("%lli %i %s\n", (timestamp() - p->s_time), p->name,
		"is thinking");
	while (1)
	{
		if (timestamp() - p->s_time > p->info->die)
		{
			printf("%lli %i %s\n", (timestamp() - p->s_time), p->name,
				"is dead");
			return (NULL);
		}
	}
	return (NULL);
}

int	error_input(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error:\nTry number_philos, time_to_die, time_to_eat,");
		printf(" time_to_sleep, (optinal) times_eaten. (In ms)\n");
		return (1);
	}
	return (0);
}

int	create_data(t_data *data)
{
	data->eat_now = NULL;
	data->fork = NULL;
	data->die = 0;
	data->eat = 0;
	data->exit = 0;
	data->must_eat = 0;
	data->nb_p_finish = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("Error:\nMalloc failed at data!\n"));
	create_data(data);
	if (error_input(argc) == 1)
	{
		free(data);
		return (0);
	}
	argv_to_int(data, argv, argc);
	if (data->fork)
		free(data->fork);
	if (data->eat_now)
		free(data->eat_now);
	free(data);
	return (0);
}
