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

int			change_fractol(int keycode, t_str *str)
{
	int prev;

	prev = str->fract.type;
	if (keycode == BUT_DEL)
		str->fract.type = (str->fract.type == 7) ? 1 : ++str->fract.type;
	else if (keycode - 17 != str->fract.type && keycode < BUT_6)
		str->fract.type = keycode - 17;
	else if (keycode == BUT_6)
		str->fract.type = 6;
	else if (keycode == BUT_5)
		str->fract.type = 5;
	else if (keycode == BUT_7)
		str->fract.type = 7;
	if (prev == str->fract.type)
		return (0);
	if (str->fract.type == 7)
	{
		str->fract.iter = 2;
		init_carpet(&str->fract);
	}
	else
		(str->fract.type == 1) ? init_fr(&str->fract, 0) :
		init_fr(&str->fract, 1);
	return (1);
}

void		init_fr(t_fractol *f, int i)
{
	if (i == 0)
	{
		init_complex(-2.16, -2.11, &(f->min));
		init_complex(2.14, 2.19, &(f->max));
		init_complex(0.285, 0.01, &(f->c));
		init_complex((f->max.re - f->min.re) / IMG_W,
	(f->max.im - f->min.im) / IMG_H, &f->zoom);
		f->iter = 75;
	}
	else
	{
		init_complex(-2.36, -2.32, &(f->min));
		init_complex(2.34, 2.38, &(f->max));
		init_complex((f->max.re - f->min.re) / IMG_W,
	(f->max.im - f->min.im) / IMG_H, &f->zoom);
		f->iter = 50;
	}
}

static int	count(t_fractol *f, int i)
{
	double	tmp;

	tmp = f->z.re;
	f->z.re = (f->type >= 5) ? fabs(CHEKDIF2(f->z.re, f->z.im)) + f->c.re
	: CHEKDIF2(f->z.re, f->z.im) + f->c.re;
	if (f->type == 3)
		f->z.im = -2 * fabs(f->z.im * tmp) + f->c.im;
	else if (f->type == 4 || f->type == 6)
		f->z.im = -2 * f->z.im * tmp + f->c.im;
	else
		f->z.im = 2 * (f->z.im * tmp) + f->c.im;
	return (++i);
}

void		fractol(t_fractol *f, t_str *str, t_complex start, t_complex finish)
{
	f->xy.re = start.re;
	while (++f->xy.re < finish.re)
	{
		f->xy.im = start.im;
		while (++f->xy.im < finish.im)
		{
			if (f->type != 1)
			{
				init_complex(f->xy.re * f->zoom.re + f->min.re,
				f->xy.im * f->zoom.im + f->min.im, &(f->c));
				init_complex(0, 0, &(f->z));
			}
			else
				init_complex(f->xy.re * f->zoom.re + f->min.re,
				f->xy.im * f->zoom.im + f->min.im, &(f->z));
			f->i = 0;
			while (f->i < f->iter && CHEKSUM2(f->z.re, f->z.im) < 4)
				f->i = count(f, f->i);
			f->result_color = choose_col(f);
			put_data(str, (int)f->xy.re, (int)(f->xy.im - (start.im + 1)),
					f->result_color);
		}
	}
}
