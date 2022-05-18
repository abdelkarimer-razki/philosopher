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

int	philos_eats(t_philo *philos)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < philos[0].n_philos)
	{
		if (philos[j].n_eats == 0)
			j++;
		i++;
	}
	return (j);
}

void	*deathcheck(void *j)
{
	t_philo			*philos;
	int				i;

	i = 0;
	philos = (t_philo *)j;
	while (1)
	{
		if (i == philos[0].n_philos)
			i = 0;
		if (gettime(&philos[i].start) * 1000 > philos[i].t_die
			&& philos[i].n_eats != 0)
		{
			printf("%d %d is dead\n", gettime(&philos[i].begin), i + 1);
			exit(0);
		}
		if (philos[0].n_arg == 6)
		{
			if (philos_eats(philos) == philos[i].n_philos)
				exit(0);
		}
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
	while (1 && philos[c].n_eats != 0)
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
		create_p(philos, arv, -1, arc);
		create_th(philos, c);
	}
	else if (arc == 6)
	{
		create_p(philos, arv, ft_atoi(arv[5]), arc);
		create_th(philos, c);
	}
	else
		return (error());
}
