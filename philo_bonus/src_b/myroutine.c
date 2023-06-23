/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myroutine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:20:03 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/23 22:52:29 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_bonus.h"

void	myroutine(t_philo *philo)
{
	philo->last_time_eat = ft_get_time_ms();
	if (pthread_create(&philo->data->mythread, NULL, ft_check_die, philo) != 0)
		return ;
	if (pthread_detach(philo->data->mythread) != 0)
		return ;
	while (1)
	{
		if (take_fork(philo))
			exit(0);
		eat(philo);
		sleep_philos(philo);
	}
	return ;
}
