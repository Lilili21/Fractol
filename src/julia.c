/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:17:27 by gfoote            #+#    #+#             */
/*   Updated: 2019/08/27 17:17:28 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_julia(t_fractol *j)
{
	init_complex(-1.5, -1.2, &(j->min));
	init_complex(1.2, 1.2, &(j->max));
	init_complex(0.285, 0.01, &(j->c));
	j->iter = 75;
}

void	julia(t_fractol *j, t_str *str)
{
	int		i;
	double	tmp;

	j->xy.re = -1;
	while (++j->xy.re < IMG_WIDTH)
	{
		j->xy.im = -1;
		while (++j->xy.im < IMG_HEIGHT)
		{
			init_complex(j->xy.re * (j->max.re - j->min.re) / IMG_WIDTH +
			j->min.re, j->xy.im * (j->max.im - j->min.im) / IMG_HEIGHT +
			j->min.im, &(j->z));
			i = 0;
			while (i++ < j->iter && pow(j->z.re, 2) + pow(j->z.im, 2) < 4)
			{
				tmp = j->z.re;
				j->z.re = pow(j->z.re, 2) - pow(j->z.im, 2) + j->c.re;
				j->z.im = 2 * j->z.im * tmp + j->c.im;
			}
			put_data(str, (int)(j->xy.re), (int)(j->xy.im),
			choose_col_b(i, j->iter));
		}
	}
}
