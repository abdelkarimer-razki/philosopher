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

void	*h(void *j)
{
	t_philo			*philos;
	static int		i = -1;
	int				c;

	philos = (t_philo *)j;
	i++;
	c = i;
	//ft_usleep(500 * (philos[c].n_philos - i));
	gettimeofday(&philos[c].begin, NULL);
	philos[c].start = philos[c].begin;
	while (1)
	{
		eating(j, c, &philos[c].start, &philos[c].begin);
		sleeping(&philos[c].n_forks, philos[c].t_sleep, &philos[c].begin, c);
		printf("%d %d is thinking\n", gettime(&philos[c].begin), c + 1);
	}
	return (j);
}

int	main(int arc, char **arv)
{
	t_philo			*philos;
	int				c;

	if (args_protection(arc, arv) == 1)
		return (1);
	c = ft_atoi(arv[1]);
	if (c == 0)
	{
		write(2, "arg error", 9);
		return (1);
	}
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
