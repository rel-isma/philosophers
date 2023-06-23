/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillo_needs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:11:18 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 21:17:49 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	ft_print_msg("has taken a left fork", philo, 0);
	if (philo->data->total_f == 1)
	{
		delay(philo->data->t_die);
		pthread_mutex_unlock(&philo->l_fork);
		return (1);
	}
	pthread_mutex_lock(philo->r_fork);
	ft_print_msg("has taken a right fork", philo, 0);
	return (0);
}

void	sleep_philos(t_philo *philo)
{
	ft_print_msg("is sleeping", philo, 0);
	delay(philo->data->t_slp);
	ft_print_msg("is thinking", philo, 0);
}

int	eat(t_philo *philo)
{
	ft_print_msg("is eating", philo, 0);
	philo->number_eat++;
	pthread_mutex_lock(&philo->time_mut);
	philo->last_time_eat = ft_get_time_ms();
	pthread_mutex_unlock(&philo->time_mut);
	delay(philo->data->t_eat);
	pthread_mutex_lock(&philo->data->meals_m);
	if (philo->number_eat == philo->data->t_try)
		philo->data->meals++;
	pthread_mutex_unlock(&philo->data->meals_m);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

void	delay(long ms)
{
	long	curr;

	curr = ms + ft_get_time_ms();
	while (ft_get_time_ms() < curr)
		usleep(100);
}

void	ft_print_msg(char *str, t_philo *philo, int flag)
{
	pthread_mutex_lock(&philo->data->stop_m);
	if (philo->data->stop == 0)
	{
		if (flag == 1 || flag == 2)
		{
			philo->data->stop = 1;
		}
		pthread_mutex_lock(&philo->data->print_m);
		if (flag != 2)
		{
			printf("%ld  %d		%s\n", ft_get_time_ms() - philo->data->t_start,
				philo->philo_nbr, str);
		}
		pthread_mutex_unlock(&philo->data->print_m);
	}
	pthread_mutex_unlock(&philo->data->stop_m);
}
