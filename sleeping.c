/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:56:39 by aer-razk          #+#    #+#             */
/*   Updated: 2022/05/10 14:56:47 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	sleeping(t_philo	*philos, struct timeval *start1, int c)
{
	printf("%d %d is sleeping\n", gettime(start1), c + 1);
	ft_usleep(philos[c].t_sleep);
}

void	ft_usleep(useconds_t time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while ((unsigned int)gettime(&start) < time / 1000)
		usleep(1);
}

int	gettime(struct timeval *start1)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000 + end.tv_usec / 1000
			- (start1->tv_sec * 1000 + start1->tv_usec / 1000)));
}
