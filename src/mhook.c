/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhook.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:54:56 by gfoote            #+#    #+#             */
/*   Updated: 2019/09/09 15:54:58 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_close(void *param)
{
	(void)param;
	exit(0);
}

static int	m_zoom(int button, int mousex, int mousey, t_str *str)
{
	t_complex k;

	init_complex(((mousex - 400) * (str->fract->max.re - str->fract->min.re)
	/ IMG_W) + str->fract->min.re, (mousey * (str->fract->max.im -
	str->fract->min.im) / IMG_H) + str->fract->min.im, &k);
	if (button == MOUSE_SC_UP || button == MOUSE_SC_LEFT)
	{
		str->fract->max.re = k.re + (str->fract->max.re - k.re) * 1.1;
		str->fract->max.im = k.im + (str->fract->max.im - k.im) * 1.1;
		str->fract->min.re = k.re + (str->fract->min.re - k.re) * 1.1;
		str->fract->min.im = k.im + (str->fract->min.im - k.im) * 1.1;
	}
	if (button == MOUSE_SC_DOWN || button == MOUSE_SC_RIGHT)
	{
		str->fract->max.re = k.re + (str->fract->max.re - k.re) / 1.1;
		str->fract->max.im = k.im + (str->fract->max.im - k.im) / 1.1;
		str->fract->min.re = k.re + (str->fract->min.re - k.re) / 1.1;
		str->fract->min.im = k.im + (str->fract->min.im - k.im) / 1.1;
	}
	init_complex((str->fract->max.re - str->fract->min.re) / IMG_W,
(str->fract->max.im - str->fract->min.im) / IMG_H, &str->fract->zoom);
	mlx_clear_window(str->map.mlx, str->map.win);
	draw(str);
	return (0);
}

int			mouse_pressed(int button, int mousex, int mousey, t_str *str)
{
	if (button == MOUSE_SC_LEFT || button == MOUSE_SC_RIGHT ||
	button == MOUSE_SC_UP || button == MOUSE_SC_DOWN)
		return (m_zoom(button, mousex, mousey, str));
	return (0);
}

int			motion_notify(int mousex, int mousey, t_str *str)
{
	if (str->fract->type == 1 && str->fract->space_pressed == 1)
	{
		str->fract->c.re = (double)(mousex - 400) / 500;
		str->fract->c.im = (double)(mousey - 300) / 500;
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str);
	}
	return (0);
}
