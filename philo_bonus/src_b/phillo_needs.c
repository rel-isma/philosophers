/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillo_needs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:11:18 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 21:14:31 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_bonus.h"

void	delay(long ms)
{
	long	curr;

	curr = ft_get_time_ms();
	while (ft_get_time_ms() < curr + ms)
		usleep(100);
}

int	take_fork(t_philo *philo)
{
	sem_wait(philo->data->fork);
	ft_print_msg("has taken a fork", philo, 0);
	if (philo->data->total_f == 1)
	{
		sem_post(philo->data->fork);
		delay(philo->data->t_die);
		ft_print_msg("die", philo, 1);
		return (1);
	}
	sem_wait(philo->data->fork);
	ft_print_msg("has taken a fork", philo, 0);
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
	sem_wait(philo->l_t_eat);
	philo->number_eat++;
	philo->last_time_eat = ft_get_time_ms();
	sem_post(philo->l_t_eat);
	delay(philo->data->t_eat);
	sem_post(philo->data->fork);
	sem_post(philo->data->fork);
	if (philo->number_eat == philo->data->t_try)
		sem_post(philo->data->finish);
	return (0);
}

void	ft_print_msg(char *str, t_philo *philo, int flag)
{
	if (flag == 1 || flag == 0)
	{
		sem_wait(philo->data->print);
		printf("%ld\t%d\t%s\n", ft_get_time_ms() - philo->data->t_start,
			philo->philo_nbr, str);
		if (flag == 1)
		{
			sem_post(philo->l_t_eat);
			sem_post(philo->data->die);
			ft_close(philo);
		}
		else
			sem_post(philo->data->print);
	}
}
