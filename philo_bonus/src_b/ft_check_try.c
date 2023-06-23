/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_try.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:35:21 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 21:08:26 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_bonus.h"

void	*ft_check_try(void *args)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *)args;
	while (philos->data->total_f > i)
	{
		sem_wait(philos->data->finish);
		i++;
	}
	sem_post(philos->data->die);
	ft_close(philos);
	return (NULL);
}
