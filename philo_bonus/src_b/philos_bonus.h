/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:42:41 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 20:48:54 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_BONUS_H
# define PHILOS_BONUS_H

# include <libc.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	sem_t		*fork;
	sem_t		*die;
	int			total_f;
	long int	t_eat;
	long int	t_slp;
	long int	t_die;
	long int	t_try;
	long int	t_start;
	sem_t		*finish;
	sem_t		*print;
	pthread_t	mythread;
}				t_data;

typedef struct s_philo
{
	int			philo_nbr;
	t_data		*data;
	pid_t		pid_philo;
	long		last_time_eat;
	sem_t		*l_t_eat;
	int			number_eat;
}				t_philo;

long			ft_atoi(const char *str);
void			delay(long ms);
int				create_thread_check_try(t_philo *philos);
size_t			ft_strlen(const char *s);
char			*ft_itoa(int n);
void			*ft_check_try(void *args);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_check_die(void *args);
int				ft_check_error(int ac, char **av);
int				eat(t_philo *philo);
void			sleep_philos(t_philo *philo);
int				take_fork(t_philo *philo);
long			ft_get_time_ms(void);
int				create_philosophers(t_philo *philos);
int				ft_init_data(t_data *data, char **av, int ac);
int				ft_init_philo(t_philo *philos, t_data *data);
void			ft_print_msg(char *str, t_philo *philo, int flag);
void			myroutine(t_philo *philo);
long			ft_get_time_ms(void);
void			ft_close(t_philo *philos);

#endif