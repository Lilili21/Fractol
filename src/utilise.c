/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:34:26 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 13:37:34 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_strdl(char **tmp)
{
	int		i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
			free(tmp[i++]);
		free(tmp);
	}
}

void		init_complex(double re, double im, t_complex *complex)
{
	complex->re = re;
	complex->im = im;
}

int			whoops(int i)
{
	if (i == 1)
		ft_putstr_fd("usage: fract [fractals]\n fractals:\n"
		"\t-->Julia\n\t-->Mandelbrot\n\t-->Burning_Ship\n\t-->Mandelbar\n\t"
		"-->Celtic_Mandelbrot\n\t-->Celtic_Mandelbar\n\t-->Carpet\n", 2);
	else if (i == 2)
		ft_putstr_fd("malloc problem", 2);
	return (-1);
}

int			ft_check_name(char *str)
{
	if (ft_strequ(str, "Julia") || ft_strequ(str, "Mandelbrot") ||
		ft_strequ(str, "Burning Ship") || ft_strequ(str, "Mandelbar") ||
		ft_strequ(str, "Celtic Mandelbrot") ||
		ft_strequ(str, "Celtic Mandelbar") || ft_strequ(str, "Carpet"))
		return (1);
	return (0);
}

int			ft_check_name2(char *fractol)
{
	char	**type;
	int		i;

	type = ft_strsplit("Julia Mandelbrot Burning_Ship Mandelbar"
					" Celtic_Mandelbrot Celtic_Mandelbar Carpet", ' ');
	i = -1;
	while (type[++i])
	{
		if (ft_strequ(type[i], fractol))
			break ;
	}
	ft_strdl(type);
	if (i >= 0 && i <= 7)
		return (++i);
	else
		return (-1);
}
