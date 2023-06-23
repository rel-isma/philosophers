/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:11:44 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 21:18:02 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

int	ft_check_die_try(t_philo *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philos->data->total_f)
		{
			pthread_mutex_lock(&philos->data->meals_m);
			if (philos->data->meals == philos->data->total_f)
				return (ft_print_msg("sss", philos, 2), ft_destroy(philos), 0);
			pthread_mutex_unlock(&philos->data->meals_m);
			pthread_mutex_lock(&philos[i].time_mut);
			if (ft_get_time_ms() > philos[i].last_time_eat
				+ philos[i].data->t_die)
			{
				pthread_mutex_unlock(&philos[i].time_mut);
				ft_print_msg("die", philos, 1);
				return (ft_destroy(philos), 0);
			}
			pthread_mutex_unlock(&philos[i].time_mut);
			i++;
			usleep(200);
		}
	}
}

int	create_philosophers(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->total_f)
	{
		if (pthread_create(&philos[i].mythread, NULL, myroutine,
				&philos[i]) != 0)
			return (1);
		if (pthread_detach(philos[i].mythread) != 0)
			return (1);
		usleep(100);
		i++;
	}
	if (ft_check_die_try(philos))
		return (0);
	return (0);
}
