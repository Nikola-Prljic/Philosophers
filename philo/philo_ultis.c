/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ultis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:24:13 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/28 16:30:26 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_time(char *msg, t_philo *p)
{
	int	time;

	time = timestamp() - p->info->start_time;
	if (time >= 0 && time <= 2147483647 && !is_dead(p, 0))
		printf("%lli %i %s\n", (timestamp() - p->info->start_time), p->name,
			msg);
	return (0);
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long long	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
}
