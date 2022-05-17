/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:56:12 by aer-razk          #+#    #+#             */
/*   Updated: 2022/05/10 14:56:14 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	create_th(t_philo *philos, int c)
{
	int	i;

	i = -1;
	while (++i < c)
		pthread_mutex_init(&philos[i].mutex, NULL);
	i = -1;
	while (++i < c)
	{
		if ((i + 1) % 2 == 0)
			ft_usleep(1000);
		pthread_create(&philos[i].thread, NULL, &h, philos);
	}
}

void	create_p(t_philo *philos, char **arv, int t)
{
	int	c;
	int	i;

	i = -1;
	c = ft_atoi(arv[1]);
	while (++i < c)
	{
		philos[i].n_philos = c;
		philos[i].t_die = ft_atoi(arv[2]) * 1000;
		philos[i].t_eat = ft_atoi(arv[3]) * 1000;
		philos[i].t_sleep = ft_atoi(arv[4]) * 1000;
		philos[i].n_eats = t;
	}
}
