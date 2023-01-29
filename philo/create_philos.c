/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:48:55 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/28 16:53:42 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_lock(t_philo *p)
{
	pthread_mutex_lock(&p->info->fork[p->name - 1]);
	pthread_mutex_lock(&p->info->print);
	print_time("has taken a fork", p);
	pthread_mutex_unlock(&p->info->print);
	pthread_mutex_lock(&p->info->fork[p->fork_next]);
	pthread_mutex_lock(&p->info->print);
	print_time("has taken a fork", p);
	pthread_mutex_unlock(&p->info->print);
}

void	fork_unlock(t_philo *p)
{
	pthread_mutex_lock(&p->info->print);
	print_time("is eating", p);
	pthread_mutex_lock(&p->info->m_eat);
	p->s_time = timestamp();
	pthread_mutex_unlock(&p->info->m_eat);
	pthread_mutex_unlock(&p->info->print);
	ft_usleep(p->info->eat);
	pthread_mutex_unlock(&p->info->fork[p->fork_next]);
	pthread_mutex_unlock(&p->info->fork[p->name - 1]);
	pthread_mutex_lock(&p->info->print);
	print_time("is sleeping", p);
	pthread_mutex_unlock(&p->info->print);
	ft_usleep(p->info->sleep);
	pthread_mutex_lock(&p->info->print);
	print_time("is thinking", p);
	pthread_mutex_unlock(&p->info->print);
}

int	eat_counter(t_philo *philo)
{
	if ((int)++philo->times_eaten == philo->info->must_eat)
	{
		pthread_mutex_lock(&philo->info->finish);
		philo->finish = 1;
		philo->info->nb_p_finish++;
		if (philo->info->nb_p_finish == philo->info->n_philo)
		{
			pthread_mutex_unlock(&philo->info->finish);
			is_dead(philo, 'y');
			return (1);
		}
		pthread_mutex_unlock(&philo->info->finish);
		return (1);
	}
	return (0);
}

void	*create_philos(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->name % 2 == 0)
		ft_usleep(philo->info->eat / 10);
	while (is_dead(philo, 'n') == 0)
	{
		pthread_create(&philo->thread_death_id, NULL, death_test, ptr);
		fork_lock(philo);
		fork_unlock(philo);
		pthread_detach(philo->thread_death_id);
		if (eat_counter(philo) == 1)
			return (NULL);
	}
	return (NULL);
}
