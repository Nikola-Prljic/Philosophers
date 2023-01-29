/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:36:51 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/28 16:30:09 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_data	*info;
	pthread_t		thread_death_id;
	pthread_t		thread;
	pthread_mutex_t	mutex_eat;
	long long		s_time;
	long long		e_time;
	int				times_eaten;
	int				fork_next;
	int				my_eat;
	int				finish;
	int				name;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	finish;
	long long		start_time;
	long long		die;
	int				must_eat;
	int				n_philo;
	int				sleep;
	int				exit;
	int				eat;
	int				nb_p_finish;
}					t_data;

void				mutex_destroy(t_data *data);
void				ft_thred_join(t_data *data);
int					is_dead(t_philo *philo, char died);
void				*death_test(void *ptr);
void				*dead_thread(void *ptr);
long long			timestamp(void);
void				ft_usleep(int ms);
int					init_philos(t_data *data);
int					print_time(char *msg, t_philo *p);
int					argv_to_int(t_data *data, char **argv, int argc);
int					ft_atoi(const char *nptr);
void				ft_thred_join(t_data *data);
void				*just_one_philo(void *ptr);
int					philo_died(t_philo *philo);
void				*create_philos(void *ptr);

#endif