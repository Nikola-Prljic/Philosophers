/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:54:58 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/28 16:29:41 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_wait(t_philo *p)
{
	pthread_mutex_lock(&p->info->m_dead);
	if (p->info->exit == 1)
	{
		pthread_mutex_unlock(&p->info->m_dead);
		return (1);
	}
	pthread_mutex_unlock(&p->info->m_dead);
	return (0);
}

void	mutex_destroy(t_data *data)
{
	int	i;

	i = 0;
	if (data->n_philo < 2)
		return ;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
}

void	ft_thred_join(t_data *data)
{
	int	i;

	while (ft_wait(data->philo) == 0)
	{
		ft_usleep(1);
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			break ;
		i++;
	}
	pthread_mutex_destroy(&data->print);
	mutex_destroy(data);
}
