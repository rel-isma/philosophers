/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:09:22 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 23:13:05 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

int	ft_check_number(char *av)
{
	int	i;

	i = 0;
	if (!av)
		return (1);
	if (av[0] == '\0')
		printf("Error: empty\n");
	if (av[i] == '+' && av[i + 1] >= '0' && av[i + 1] <= '9')
		i++;
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
		{
			if (av[i] == '-' && av[i + 1] >= '0' && av[i + 1] <= '9'
				&& !(av[i - 1] >= '0' && av[i - 1] <= '9'))
				printf("Error : mymknch dakhl 3adad salib\n");
			else
				printf("Error : rak dkhlti chi haja mn ghir number\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac > 6)
	{
		write(1, "mymknch rak dkhlti bzaf agms\n", 30);
		return (1);
	}
	if (ac < 5)
	{
		write(1, "mazal tzid chi agrms\n", 22);
		return (1);
	}
	if (ac == 5 || ac == 6)
	{
		while (av[i])
		{
			if (ft_check_number(av[i]))
				return (1);
			i++;
		}
	}
	return (0);
}
