/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:15:29 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 12:04:01 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

int	ft_init_philo(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_f)
	{
		philos[i].philo_nbr = i + 1;
		philos[i].data = data;
		philos[i].last_time_eat = 0;
		philos[i].number_eat = 0;
		pthread_mutex_init(&philos[i].l_fork, NULL);
		pthread_mutex_init(&philos[i].time_mut, NULL);
		if (data->total_f == 1)
			return (0);
		if (i != data->total_f - 1)
			philos[i].r_fork = &philos[i + 1].l_fork;
		else
			philos[i].r_fork = &philos[0].l_fork;
		i++;
	}
	return (0);
}

int	ft_init_ags(t_data *data, int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		data->meals = 0;
		data->stop = 0;
		pthread_mutex_init(&data->meals_m, NULL);
		pthread_mutex_init(&data->stop_m, NULL);
		pthread_mutex_init(&data->print_m, NULL);
		data->t_start = ft_get_time_ms();
		data->total_f = ft_atoi(av[1]);
		if (data->total_f == 0)
			return (1);
		data->t_die = ft_atoi(av[2]);
		if (data->t_die == 0)
			return (2);
		data->t_eat = ft_atoi(av[3]);
		if (data->t_eat == 0)
			return (3);
		data->t_slp = ft_atoi(av[4]);
		if (data->t_slp == 0)
			return (4);
	}
	return (0);
}

int	ft_init_data(t_data *data, char **av, int ac)
{
	int	i;

	if (ac == 6)
	{
		data->t_try = ft_atoi(av[5]);
		if (data->t_try == 0)
			return (5);
	}
	i = ft_init_ags(data, ac, av);
	return (i);
}
