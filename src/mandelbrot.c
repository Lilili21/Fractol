/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:17:35 by gfoote            #+#    #+#             */
/*   Updated: 2019/08/27 17:17:41 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	init_complex(double re, double im, t_complex *complex)
{
	complex->re = re;
	complex->im = im;
}

void	increase_complex(t_complex *complex, int inc)
{
	complex->re +=inc;
	complex->im +=inc;
}

void	initialize_mandel(t_fractol *m)
{
	init_complex(-2.1, -1.2, &(m->min));
	init_complex(0.6, 1.2, &(m->max));
	init_complex(m->max.re-m->min.re, m->max.im - m->min.im, &m->zoom);
	m->iter = 50;
}

void	mandelbrot(t_fractol *m, t_str *str)
{
	int		i;
	double	tmp;

	(m->xy).re = -1;
	while (++m->xy.re < IMG_WIDTH)
	{
		m->xy.im = -1;
		while (++m->xy.im < IMG_HEIGHT)
		{
			init_complex((m->xy.re * m->zoom.re / IMG_WIDTH )+ m->min.re,
			(m->xy.im * m->zoom.im / IMG_HEIGHT ) + m->min.im, &(m->c));
			init_complex(0, 0, &(m->z));
			i = 0;
			while (i++ < m->iter && pow(m->z.re, 2) + pow(m->z.im, 2) < 4)
			{
				tmp = m->z.re;
				m->z.re = pow(m->z.re, 2) - pow(m->z.im, 2) + m->c.re;
				m->z.im = 2 * m->z.im * tmp + m->c.im;
			}
			put_data(str, (int)(m->xy.re), (int)(m->xy.im),
			choose_col_b(i, m->iter));
		}
	}
}
