/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:12:54 by aer-razk          #+#    #+#             */
/*   Updated: 2022/05/10 15:12:56 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	lock_mutex_even(void *j, int c, struct timeval *start1)
{
	t_philo			*philos;

	philos = (t_philo *)j;
	pthread_mutex_lock(&philos[c].mutex);
	printf("%d %d has taken a fork\n", gettime(start1), c + 1);
	if (c == philos[c].n_philos - 1)
		pthread_mutex_lock(&philos[0].mutex);
	else
		pthread_mutex_lock(&philos[c + 1].mutex);
	printf("%d %d has taken a fork\n", gettime(start1), c + 1);
}

void	unlock_mutex_even(void *j, int c)
{
	t_philo			*philos;

	philos = (t_philo *)j;
	pthread_mutex_unlock(&philos[c].mutex);
	if (c == philos[c].n_philos - 1)
		pthread_mutex_unlock(&philos[0].mutex);
	else
		pthread_mutex_unlock(&philos[c + 1].mutex);
}

void	lock_mutex_odd(void *j, int c, struct timeval *start1)
{
	t_philo			*philos;

	philos = (t_philo *)j;
	if (c == philos[c].n_philos - 1)
		pthread_mutex_lock(&philos[0].mutex);
	else
		pthread_mutex_lock(&philos[c + 1].mutex);
	printf("%d %d has taken a fork\n", gettime(start1), c + 1);
	pthread_mutex_lock(&philos[c].mutex);
	printf("%d %d has taken a fork\n", gettime(start1), c + 1);
}

void	unlock_mutex_odd(void *j, int c)
{
	t_philo			*philos;

	philos = (t_philo *)j;
	if (c == philos[c].n_philos - 1)
		pthread_mutex_unlock(&philos[0].mutex);
	else
		pthread_mutex_unlock(&philos[c + 1].mutex);
	pthread_mutex_unlock(&philos[c].mutex);
}

void	eating(void *j, int c, struct timeval *start, struct timeval *start1)
{
	t_philo			*philos;

	philos = (t_philo *)j;
	if ((c + 1) % 2 == 0)
		lock_mutex_even(j, c, start1);
	else
		lock_mutex_odd(j, c, start1);
	gettimeofday(start, NULL);
	printf("%d %d is eating\n", gettime(start1), c + 1);
	ft_usleep(philos[c].t_eat);
	if ((c + 1) % 2 == 0)
		unlock_mutex_even(j, c);
	else
		unlock_mutex_odd(j, c);
}
