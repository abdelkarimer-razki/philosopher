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

void	lockprint(t_philo *philos, int c)
{
	int	i;

	i = -1;
	while (++i < c)
		pthread_mutex_lock(&philos[i].print);
}

int	philos_eats(t_philo *philos)
{
	int	j;

	j = 0;
	while (j < philos[j].n_philos)
	{
		if (philos[j].n_eats == 0)
			j++;
	}
	return (j);
}

int	deathcheck(t_philo *philos, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == c)
			i = 0;
		if (gettime(&philos[i].start) * 1000 > philos[i].t_die + 5
			&& philos[i].n_eats > 0)
		{
			printf("%d %d is dead\n", gettime(&philos[i].begin), i + 1);
			return (0);
		}
		if (philos_eats(philos) == philos[i].n_philos)
			return (0);
		i++;
	}
}

int	error(void)
{
	write(2, "arg error", 9);
	return (1);
}

void	*h(void *j)
{
	t_philo			*philos;
	static int		i = -1;
	int				c;

	philos = (t_philo *)j;
	i++;
	c = i;
	gettimeofday(&philos[c].begin, NULL);
	philos[c].start = philos[c].begin;
	while (1 && philos[c].n_eats)
	{
		eating(j, c, &philos[c].start, &philos[c].begin);
		philos[c].n_eats--;
		sleeping(philos, &philos[c].begin, c);
		printf("%d %d is thinking\n", gettime(&philos[c].begin), c + 1);
	}
	return (j);
}

int	main(int arc, char **arv)
{
	t_philo			*philos;
	int				c;
	int	i;

	i = 0;

	if (args_protection(arc, arv) == 1)
		return (error());
	c = ft_atoi(arv[1]);
	if (c == 0)
		return (error());
	philos = malloc(c * sizeof(t_philo));
	if (!philos)
		return (1);
	if (arc == 5)
	{
		create_p(philos, arv, -1);
		create_th(philos, c);
		return (deathcheck(philos, c));
	}
	else if (arc == 6)
	{
		create_p(philos, arv, ft_atoi(arv[5]));
		create_th(philos, c);
		return (deathcheck(philos, c));
	}
	else
		return (error());
}
