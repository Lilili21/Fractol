/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:45:19 by gfoote            #+#    #+#             */
/*   Updated: 2019/09/18 15:45:21 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_carpet(t_fractol *f)
{
	if (f->color == 0)
		f->color_mad = 0xFF0000;
	else if (f->color == 1)
		f->color_mad = 0x00FF00;
	else if (f->color == 2)
		f->color_mad = 0x0000FF;
	else
		f->color_mad = 0xFFFFFF;
	init_complex(IMG_W / 3, IMG_H / 3, &f->max);
}

static int	count(t_fractol *f, t_complex t, int iter, int color)
{
	f->i = 1;
	init_complex(IMG_W / 3, IMG_H / 3, &f->max);
	while (++f->i < iter)
		init_complex(f->max.re / 3, f->max.im / 3, &f->max);
	f->i = -1;
	while (++f->i < iter)
	{
		f->min.re = t.re;
		f->min.im = t.im;
		while (t.re > 0 || t.im > 0)
		{
			if ((int)(t.re / f->max.re) % 3 == 1 &&
			(int)(t.im / f->max.im) % 3 == 1)
				return (color);
			t.re /= 3;
			t.im /= 3;
		}
		f->max.re *= 3;
		f->max.im *= 3;
	}
	return (0x000000);
}

void		carpet(t_fractol *f, t_str *str, t_complex start, t_complex finish)
{
	f->xy.re = start.re + 1;
	f->xy.im = start.im;
	while (f->xy.re < finish.re && ++f->xy.im < finish.im)
	{
		f->result_color = count(f, f->xy, f->iter, f->color_mad);
		put_data(str, (int)f->xy.re, (int)(f->xy.im - (start.im + 1)),
		f->result_color);
		if (f->xy.im == finish.im - 1)
		{
			f->xy.im = start.im;
			f->xy.re++;
		}
	}
}
