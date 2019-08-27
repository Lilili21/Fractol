/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:56:24 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/15 13:03:27 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;
	long int	lmax;

	lmax = 9223372036854775807;
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	(str[i] == '+' || str[i] == '-') ? i++ : i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign > 0 && ((result > lmax / 10)
		|| (result == lmax / 10 && str[i] - '0' > 7)))
			return (-1);
		else if (sign < 0 && ((result > lmax / 10)
		|| (result == lmax / 10 && str[i] - '0' > 8)))
			return (0);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
