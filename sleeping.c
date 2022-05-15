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

void	sleeping(int *forks, int sleep, struct timeval *start1, int c)
{
	if (*forks == 2)
	{
		*forks = 1;
		printf("%d %d is sleeping\n", gettime(start1), c + 1);
		ft_usleep(sleep);
	}
}

void	ft_usleep(useconds_t time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while ((unsigned int)gettime(&start) < time / 1000)
		usleep(1);
}
