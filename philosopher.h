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
	int	n_philos;
	int	t_die;
	int	n_forks;
	int	t_eat;
	pthread_t		thread;
	int	t_sleep;
	int	n_eats;
	pthread_mutex_t	mutex;
}	t_philo;
int		ft_atoi(const char *str);
#endif