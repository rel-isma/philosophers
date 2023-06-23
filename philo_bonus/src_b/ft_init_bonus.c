/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:59:18 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 20:58:27 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_bonus.h"

void	ft_close(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->total_f)
	{
		sem_close(philos[i].l_t_eat);
		i++;
	}
	sem_post(philos->data->finish);
	sem_close(philos->data->finish);
	sem_close(philos->data->fork);
	sem_close(philos->data->die);
	sem_close(philos->data->print);
}

int	ft_init_philo(t_philo *philos, t_data *data)
{
	int		i;
	char	*str;
	char	*itoa;

	i = 0;
	while (i < data->total_f)
	{
		philos[i].philo_nbr = i + 1;
		philos[i].data = data;
		philos[i].last_time_eat = 0;
		philos[i].number_eat = 0;
		itoa = ft_itoa(i);
		str = ft_strjoin("/my_semaphore_eat", itoa);
		sem_unlink(str);
		philos[i].l_t_eat = sem_open(str, O_CREAT, 0644, 1);
		if (philos[i].l_t_eat == SEM_FAILED)
		{
			printf("Error : semaphore");
			return (1);
		}
		free(str);
		free(itoa);
		i++;
	}
	return (0);
}

int	create_sem(char *str, sem_t **sem_all, int i)
{
	sem_unlink(str);
	*sem_all = sem_open(str, O_CREAT, 0644, i);
	if (*sem_all == SEM_FAILED)
	{
		printf("error: sem_open\n");
		return (1);
	}
	return (0);
}

int	ft_init_ags(t_data *data, int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		data->t_start = ft_get_time_ms();
		data->total_f = ft_atoi(av[1]);
		if (data->total_f == 0)
			return (1);
		data->t_die = ft_atoi(av[2]);
		if (data->t_die == 0)
			return (1);
		data->t_eat = ft_atoi(av[3]);
		if (data->t_eat == 0)
			return (1);
		data->t_slp = ft_atoi(av[4]);
		if (data->t_slp == 0)
			return (1);
		if (create_sem("/print_sem", &data->print, 1))
			return (1);
		if (create_sem("/my_semaphore_death", &data->die, 0))
			return (1);
		if (create_sem("/my_semaphore", &data->fork, data->total_f))
			return (1);
		if (create_sem("/my_semaphore_finish", &data->finish, 0))
			return (1);
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
			return (1);
	}
	i = ft_init_ags(data, ac, av);
	return (i);
}
