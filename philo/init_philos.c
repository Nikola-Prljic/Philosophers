/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:42:32 by nprljic           #+#    #+#             */
/*   Updated: 2023/04/21 09:29:32 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	next_fork(t_philo *philo)
{
	if (philo->name == philo->info->n_philo)
		return (0);
	return (philo->name);
}

void	make_philos_data(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = timestamp();
	while (i < data->n_philo)
	{
		data->philo[i].name = i + 1;
		data->philo[i].s_time = 0;
		data->philo[i].my_eat = 0;
		data->philo[i].my_eat = 0;
		data->philo[i].e_time = 0;
		data->philo[i].times_eaten = 0;
		data->philo[i].finish = 0;
		pthread_mutex_init(&data->fork[i], NULL);
		data->eat_now[i] = 0;
		i++;
	}
}

void	make_more_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].info = data;
		data->philo[i].fork_next = next_fork(&data->philo[i]);
		data->philo[i].s_time = timestamp();
		pthread_create(&data->philo[i].thread, NULL, &create_philos,
			(void *)&data->philo[i]);
		i++;
	}
}

int	init_philos(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (1);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->fork)
		return (1);
	data->eat_now = malloc(sizeof(int) * data->n_philo);
	if (!data->eat_now)
		return (1);
	if (data->n_philo == 1)
	{
		data->philo[0].name = 1;
		data->philo[0].info = data;
		pthread_create(&data->philo[0].thread, NULL, &just_one_philo,
			(void *)&data->philo[0]);
		pthread_join(data->philo[0].thread, NULL);
		return (0);
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	pthread_mutex_init(&data->m_dead, NULL);
	pthread_mutex_init(&data->finish, NULL);
	make_philos_data(data);
	make_more_philos(data);
	ft_thred_join(data);
	return (0);
}
