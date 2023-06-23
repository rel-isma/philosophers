/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:10:47 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 12:20:40 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

int	main(int ac, char *av[])
{
	t_data	*data;
	t_philo	*philos;
	int		check_init;

	if (ft_check_error(ac, av))
		return (0);
	data = malloc(sizeof(t_data));
	check_init = ft_init_data(data, av, ac);
	if (check_init != 0)
	{
		free(data);
		return (0);
	}
	philos = malloc(sizeof(t_philo) * data->total_f);
	if (!philos)
		return (1);
	if (ft_init_philo(philos, data))
		free(data);
	if (create_philosophers(philos))
		free(philos);
	return (0);
}
