/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:41:53 by gfoote            #+#    #+#             */
/*   Updated: 2019/04/15 13:03:22 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_base(int n)
{
	int			base;

	base = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		base++;
	while (n > 0)
	{
		base++;
		n = n / 10;
	}
	return (base);
}

char			*ft_itoa(int n)
{
	char		*result;
	int			base;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	base = ft_base(n);
	result = ((n < 0) ? ft_strnew(base + 1) : ft_strnew(base));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (base > 0)
	{
		if (result[0] != '-')
			base--;
		result[base] = n % 10 + '0';
		n = n / 10;
		if (result[0] == '-')
			base--;
	}
	return (result);
}
