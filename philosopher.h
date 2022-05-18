/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:57:30 by aer-razk          #+#    #+#             */
/*   Updated: 2022/05/10 14:57:32 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<mlx.h>
# include<sys/time.h> 

typedef struct philosopher
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	pthread_t		thread;
	int				t_sleep;
	struct timeval	begin;
	struct timeval	start;
	int				n_eats;
	pthread_mutex_t	print;
	int				n_arg;
	pthread_mutex_t	mutex;
}	t_philo;
int		ft_atoi(const char *str);
void	sleeping(t_philo	*philos, struct timeval *start1, int c);
void	ft_usleep(useconds_t time);
void	create_th(t_philo *philos, int c);
void	create_p(t_philo *philos, char **arv, int t, int arc);
void	*h(void *j);
void	*deathcheck(void *j);
int		ft_isntdigit(char *arv);
void	eating(void *j, int c, struct timeval *start, struct timeval *start1);
int		args_protection(int arc, char **arv);
void	ft_putnbr_fd(int n);
int		gettime(struct timeval *start);
#endif
