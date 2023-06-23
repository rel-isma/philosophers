/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:10:17 by rel-isma          #+#    #+#             */
/*   Updated: 2023/06/22 21:35:08 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillo.h"

long	ft_atoi(const char *str)
{
	long	i;
	long	r;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			s = -s;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i++] - '0';
	}
	if ((s * r) > INT_MAX || (r * s) < INT_MIN)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (r * s);
}
