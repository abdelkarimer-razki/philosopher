/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philisopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:08:28 by aer-razk          #+#    #+#             */
/*   Updated: 2022/04/14 23:08:29 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_isntdigit(char *arv)
{
	int	i;

	i = -1;
	while (arv[++i])
	{
		if ((arv[i] == '-' || arv[i] == '+') && (i == 0))
			i++;
		else if ((arv[i] == '-' || arv[i] == '+') && (i > 0))
			return (1);
		if (arv[i] > '9' || arv[i] < '0')
			return (1);
	}
	if (i == 0)
		return (1);
	return (-1);
}

int	args_protection(int arc, char **arv)
{
	int	i;

	i = 0;
	if (arc != 5 && arc != 6)
		return (1);
	while (arv[++i])
		if (ft_isntdigit(arv[i]) == 1 || ft_atoi(arv[i]) < 0)
			return (1);
	return (-1);
}

void	*h(void *j)
{
	t_philo			*philos;
	static int		i = -1;
	int				c;
	struct timeval	start;
	struct timeval	end;

	philos = (t_philo *)j;
	i++;
	c = i;
	usleep(200 * (philos[c].n_philos - c + 1));
	gettimeofday(&start, NULL);
	while (1 && end.tv_usec - start.tv_usec < philos[c].t_die)
	{
		pthread_mutex_lock(&philos[c].mutex);
		if (c == philos[c].n_philos)
			pthread_mutex_lock(&philos[0].mutex);
		else
			pthread_mutex_lock(&philos[c + 1].mutex);
		gettimeofday(&start, NULL);
		printf("%d %d has taken a fork\n", start.tv_usec, c + 1);
		philos[c].n_forks++;
		gettimeofday(&start, NULL);
		printf("%d %d is eating\n", start.tv_usec, c + 1);
		usleep(philos[c].t_eat);
		if (c == philos[c].n_philos)
			pthread_mutex_unlock(&philos[0].mutex);
		else
			pthread_mutex_unlock(&philos[c + 1].mutex);
		pthread_mutex_unlock(&philos[c].mutex);
		if (philos[c].n_forks == 2)
		{
			gettimeofday(&start, NULL);
			printf("%d %d is sleeping\n", start.tv_usec, c + 1);
			philos[c].n_forks--;
			usleep(philos[c].t_sleep);
		}
		printf("%d is thinking\n", c + 1);
		gettimeofday(&end, NULL);
	}
	gettimeofday(&start, NULL);
	printf("%d %d is dead\n", start.tv_usec, c + 1);
	exit(1);
	return (j);
}

void	create_th(t_philo *philos, int c)
{
	int	i;

	i = -1;
	while (++i < c)
	{
		pthread_mutex_init(&philos[i].mutex, NULL);
		pthread_create(&philos[i].thread, NULL, &h, philos);
		usleep(250);
	}
	pthread_join(philos[i - 1].thread, NULL);
}

void	create_p(t_philo *philos, char **arv)
{
	int	c;
	int	i;

	i = -1;
	c = ft_atoi(arv[1]);
	while (++i < c)
	{
		philos[i].n_philos = c - 1;
		philos[i].t_die = ft_atoi(arv[2]);
		philos[i].t_eat = ft_atoi(arv[3]);
		philos[i].t_sleep = ft_atoi(arv[4]);
		philos[i].n_forks = 1;
	}
}

int	main(int arc, char **arv)
{
	t_philo			*philos;
	int				c;

	if (args_protection(arc, arv) == 1)
		return (1);
	c = ft_atoi(arv[1]);
	philos = malloc(c * sizeof(t_philo));
	if (!philos)
		return (1);
	if (arc == 5)
	{
		create_p(philos, arv);
		create_th(philos, c);
	}
	else if (arc == 6)
	{
	}
	else
	{
		write(2, "arg error", 9);
		return (1);
	}
}
