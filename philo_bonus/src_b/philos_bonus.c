/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:33:11 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 21:07:18 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_bonus.h"

void	ft_free(t_data *data, t_philo *ph)
{
	free(data);
	free(ph);
}

int	main(int ac, char *av[])
{
	t_data	*data;
	t_philo	*philos;
	int		check_init;

	if (ft_check_error(ac, av))
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	check_init = ft_init_data(data, av, ac);
	if (check_init != 0)
		return (free(data), 1);
	philos = malloc(sizeof(t_philo) * data->total_f);
	if (!philos)
		return (free(data), 1);
	if (ft_init_philo(philos, data))
		return (ft_free(data, philos), 1);
	if (create_philosophers(philos))
		return (ft_free(data, philos), 1);
	ft_free(data, philos);
	return (0);
}
