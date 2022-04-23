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
	{
		return (1);
	}
}

int	args_protection(int arc, char **arv)
{
	int	i;

	i = -1;
	if (arc != 5 && arc != 6)
		return (1);
	while (++i)
	{
		if (ft_isntdigit(arv[i]))
			return (1);
	}
	return (-1);

}

int	ft_atoi(const char *str)
{
	char		*c;
	size_t		k;
	size_t		m;

	c = (char *)str;
	m = 1;
	k = 0;
	while (*c == ' ' || *c == '\n'
		|| *c == '\t' || *c == '\r'
		|| *c == '\f' || *c == '\v' )
	{
		c++;
	}
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			m = m * -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
	{
		k = (*c - 48) + k * 10;
		c++;
	}
	return ((int)(k * m));
}

int	create_p_t(pthread_t *threads, t_philo *philos, char **arv)
{
	int	c;
	int	i;

	i = -1;
	c = ft_atoi(arv[1]);
	(void)threads;
	while (++i < c)
	{
		philos[i].n_philos = i;
		philos[i].t_die = ft_atoi(arv[2]);
		philos[i].t_eat = ft_atoi(arv[3]);
		philos[i].t_sleep = ft_atoi(arv[4]);
		philos[i].n_forks = 1;
	}
	return (-1);
}

int	main(int arc, char **arv)
{
	pthread_t		*threads;
	t_philo			*philos;
	pthread_mutex_t	mutex;
	int				c;

	if (args_protection(arc, arv) == 1)
		return (1);
	pthread_mutex_init(&mutex, NULL);
	c = ft_atoi(arv[1]);
	threads = malloc(c * sizeof(pthread_t));
	if (!threads)
		return (1);
	philos = malloc(c * sizeof(t_philo));
	if (!philos)
		return (1);
	if (arc == 5)
	{
		create_p_t(threads, philos, arv);
		printf("philos[%d]'s time to die:%d",philos[2].n_philos, philos[2].t_die);
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
