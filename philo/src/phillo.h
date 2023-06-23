/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:12:11 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 21:16:51 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILLO_H
# define PHILLO_H

# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				total_f;
	long int		t_eat;
	long int		t_slp;
	long int		t_die;
	long int		t_try;
	long int		meals;
	pthread_mutex_t	meals_m;
	long int		t_start;
	pthread_mutex_t	print_m;
	int				death;
	pthread_mutex_t	stop_m;
	int				stop;
}					t_data;

typedef struct s_philo
{
	pthread_t		mythread;
	int				philo_nbr;
	t_data			*data;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	time_mut;
	long			last_time_eat;
	int				number_eat;

}					t_philo;

long				ft_atoi(const char *str);
void				delay(long ms);
int					ft_check_error(int ac, char **av);
int					eat(t_philo *philo);
void				sleep_philos(t_philo *philo);
int					take_fork(t_philo *philo);
long				ft_get_time_ms(void);
int					create_philosophers(t_philo *philos);
int					ft_init_data(t_data *data, char **av, int ac);
int					ft_init_philo(t_philo *philos, t_data *data);
void				ft_print_msg(char *str, t_philo *philo, int flag);
void				*myroutine(void *args);
long				ft_get_time_ms(void);
void				ft_destroy(t_philo *philos);

#endif