/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:11:42 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/28 16:31:00 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, char died)
{
	pthread_mutex_lock(&philo->info->m_dead);
	if (died == 'y')
		philo->info->exit = 1;
	if (philo->info->exit == 1)
	{
		pthread_mutex_unlock(&philo->info->m_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->m_dead);
	return (0);
}

void	*death_test(void *ptr)
{
	t_philo	*p;

	p = (t_philo *)ptr;
	ft_usleep(p->info->die + 1);
	pthread_mutex_lock(&p->info->m_eat);
	pthread_mutex_lock(&p->info->finish);
	if (is_dead(p, 'n') == 0 && !p->finish && (timestamp()
			- p->s_time) >= p->info->die)
	{
		pthread_mutex_unlock(&p->info->m_eat);
		pthread_mutex_unlock(&p->info->finish);
		pthread_mutex_lock(&p->info->print);
		print_time("dead", p);
		pthread_mutex_unlock(&p->info->print);
		is_dead(p, 'y');
		return (NULL);
	}
	pthread_mutex_unlock(&p->info->m_eat);
	pthread_mutex_unlock(&p->info->finish);
	return (NULL);
}
