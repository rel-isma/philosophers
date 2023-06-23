/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillo_needs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:17:33 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 12:04:23 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

long	ft_get_time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_destroy(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->total_f)
	{
		pthread_mutex_destroy(&philos[i].l_fork);
		pthread_mutex_destroy(&philos[i].time_mut);
		i++;
	}
	pthread_mutex_destroy(&philos->data->stop_m);
	pthread_mutex_destroy(&philos->data->print_m);
	pthread_mutex_destroy(&philos->data->meals_m);
}
