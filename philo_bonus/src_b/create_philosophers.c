/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:11:44 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/23 22:51:33 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_bonus.h"

void	*ft_check_die(void *args)
{
	t_philo	*philos;

	philos = (t_philo *)args;
	while (1)
	{
		sem_wait(philos->l_t_eat);
		if (ft_get_time_ms() > philos->last_time_eat + philos->data->t_die)
		{
			ft_print_msg("die", philos, 1);
			return (NULL);
		}
		sem_post(philos->l_t_eat);
		usleep(200);
	}
}

int	create_thread_check_try(t_philo *philos)
{
	if (pthread_create(&philos->data->mythread, NULL, ft_check_try,
			philos) != 0)
		return (1);
	if (pthread_detach(philos->data->mythread) != 0)
		return (1);
	return (0);
}

void	ft_kill(t_philo *philos)
{
	int	j;

	j = 0;
	while (j < philos->data->total_f)
	{
		if (philos[j].pid_philo != 0)
			kill(philos[j].pid_philo, SIGINT);
			j++;
	}
}

int	create_philosophers(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->total_f)
	{
		philos[i].pid_philo = fork();
		if (philos[i].pid_philo < 0)
			printf("Error: fork");
		if (philos[i].pid_philo == 0)
			myroutine(&philos[i]);
		usleep(100);
	}
	if (create_thread_check_try(philos))
		return (1);
	sem_wait(philos->data->die);
	ft_kill(philos);
	return (0);
}
