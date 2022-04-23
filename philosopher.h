#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<mlx.h>

typedef struct philosopher
{
	int	n_philos;
	int	t_die;
	int	n_forks;
	int	t_eat;
	int	t_sleep;
	int	n_eats;
}	t_philo;
#endif