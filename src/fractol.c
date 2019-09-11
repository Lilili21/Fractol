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
	if (keycode == BUT_DEL)
		str->fract->type = (str->fract->type == 6) ? 1 : ++str->fract->type;
	else if (keycode - 17 != str->fract->type && keycode < BUT_6)
		str->fract->type = keycode - 17;
	else if (keycode == BUT_6 && str->fract->type != 6)
		str->fract->type = 6;
	else if (keycode == BUT_5 && str->fract->type != 5)
		str->fract->type = 5;
	(str->fract->type == 1) ? init_fr(str->fract, 0) :
	init_fr(str->fract, 1);
	mlx_clear_window(str->map.mlx, str->map.win);
	draw(str);
	return (0);
}

void		init_fr(t_fractol *f, int i)
{
	if (i == 0)
	{
		init_complex(-1.9, -1.6, &(f->min));
		init_complex(1.6, 1.9, &(f->max));
		init_complex(0.285, 0.01, &(f->c));
		init_complex((f->max.re - f->min.re) / IMG_W,
	(f->max.im - f->min.im) / IMG_H, &f->zoom);
		f->iter = 75;
	}
	else
	{
		init_complex(-2.6, -2.2, &(f->min));
		init_complex(2.1, 2.5, &(f->max));
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

void		*fractol(t_fractol *f, t_str *str)
{
	int		i;

	(f->xy).re = -1;
	while (++f->xy.re < IMG_W)
	{
		f->xy.im = -1;
		while (++f->xy.im < IMG_H)
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
			i = 0;
			while (i < f->iter && CHEKSUM2(f->z.re, f->z.im) < 4)
				i = count(f, i);
			put_data(str, (int)(f->xy.re), (int)(f->xy.im),
			choose_col(i, f->iter, f->color, f->color_mad));
		}
	}
	return (NULL);
}
