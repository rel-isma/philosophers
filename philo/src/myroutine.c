/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myroutine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:20:03 by rel-isma          #+#    #+#             */
/*   Updated: 2023/05/21 20:49:20 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

void	*myroutine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->time_mut);
	philo->last_time_eat = ft_get_time_ms();
	pthread_mutex_unlock(&philo->time_mut);
	while (1)
	{
		if (take_fork(philo))
			return (NULL);
		eat(philo);
		sleep_philos(philo);
	}
	return (NULL);
}
