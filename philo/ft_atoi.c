/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:11:53 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/23 20:40:02 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_overlong(long long int num_size, long long int min,
		long long int num)
{
	if (num_size > 18 && min == 1)
		return (-1);
	if (num_size > 18 && min == -1)
		return (0);
	return (num * min);
}

static int	ft_space_i(long long i, const char *nptr)
{
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long long int	i;
	long long int	num_size;
	long long int	num;
	long long int	min;

	num_size = 0;
	min = 1;
	num = 0;
	i = 0;
	i = ft_space_i(i, nptr);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			min *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		num_size++;
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (ft_overlong(num_size, min, num));
}
