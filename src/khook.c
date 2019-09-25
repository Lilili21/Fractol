/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:21:29 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 13:25:45 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_esc_del_iter(int key, t_str *str)
{
	int i;

	i = 0;
	if ((str->fract.type != 7 && ((key == BUT_PLUS && str->fract.iter < 500)
		|| (key == BUT_MINUS && str->fract.iter > 10))) ||
		(str->fract.type == 7 && ((key == BUT_MINUS && str->fract.iter > 2)
		|| key == BUT_PLUS)))
		i = 1;
	if (key == BUT_ESCAPE)
	{
		mlx_destroy_window(str->map.mlx, str->map.win);
		exit(0);
	}
	else if (str->fract.type == 7)
	{
		if (key == BUT_PLUS)
			str->fract.iter += 1;
		else if (str->fract.iter > 2 && key == BUT_MINUS)
			str->fract.iter -= 1;
	}
	else if (key == BUT_PLUS)
		str->fract.iter = (str->fract.iter < 490) ? str->fract.iter + 10 : 500;
	else if (key == BUT_MINUS)
		str->fract.iter = (str->fract.iter > 10) ? str->fract.iter - 10 : 0;
	return (i);
}

static int	key_color(int key, t_str *str)
{
	if (key == BUT_P)
	{
		str->fract.ps = (str->fract.ps == 0) ? 1 : 0;
		str->fract.ps_time = 0;
	}
	else if (key == BUT_LEFT)
		str->fract.color = (str->fract.color == 0) ? 4 : --str->fract.color;
	else if (key == BUT_RIGHT)
		str->fract.color = (str->fract.color == 4) ? 0 : ++str->fract.color;
	else if (key == BUT_DOWN)
		str->fract.color_mad = (str->fract.color_mad / 10 < 1) ? 1 :
		str->fract.color_mad / 10;
	else
		str->fract.color_mad = (str->fract.color_mad * 10 > 10000000) ?
		10000000 : str->fract.color_mad * 10;
	if (str->fract.type == 7)
		init_carpet(&str->fract);
	return (1);
}

static int	key_move(int keycode, t_str *str)
{
	if (str->fract.type == 7)
		return (0);
	if (keycode == BUT_N_LEFT)
	{
		str->fract.min.re += 0.01;
		str->fract.max.re += 0.01;
	}
	else if (keycode == BUT_N_RIGHT)
	{
		str->fract.min.re -= 0.01;
		str->fract.max.re -= 0.01;
	}
	else if (keycode == BUT_N_DOWN)
	{
		str->fract.min.im -= 0.01;
		str->fract.max.im -= 0.01;
	}
	else
	{
		str->fract.min.im += 0.01;
		str->fract.max.im += 0.01;
	}
	return (1);
}

static int	key_zoom(int keycode, t_str *str)
{
	if (str->fract.type == 7)
		return (0);
	if (keycode == BUT_N_MINUS)
	{
		str->fract.min.re *= 1.1;
		str->fract.max.re *= 1.1;
		str->fract.min.im *= 1.1;
		str->fract.max.im *= 1.1;
	}
	else
	{
		str->fract.min.re /= 1.1;
		str->fract.max.re /= 1.1;
		str->fract.min.im /= 1.1;
		str->fract.max.im /= 1.1;
	}
	init_complex((str->fract.max.re - str->fract.min.re) / IMG_W,
(str->fract.max.im - str->fract.min.im) / IMG_H, &str->fract.zoom);
	return (1);
}

int			key_pressed(int keycode, t_str *str)
{
	int change;

	change = 0;
	if (keycode == BUT_ESCAPE || keycode == BUT_PLUS || keycode == BUT_MINUS)
		change = key_esc_del_iter(keycode, str);
	else if (keycode == BUT_RIGHT || keycode == BUT_LEFT ||
	keycode == BUT_UP || keycode == BUT_DOWN || keycode == BUT_P)
		change = (key_color(keycode, str));
	else if (keycode == BUT_N_UP || keycode == BUT_N_DOWN
			|| keycode == BUT_N_RIGHT || keycode == BUT_N_LEFT)
		change = (key_move(keycode, str));
	else if (keycode == BUT_N_MINUS || keycode == BUT_N_PLUS)
		change = (key_zoom(keycode, str) == 1);
	else if ((keycode >= BUT_1 && keycode <= BUT_5) || keycode == BUT_DEL
	|| keycode == BUT_7)
		change = (change_fractol(keycode, str));
	else if (str->fract.type == 1 && keycode == BUT_SPACE && ++change < 3)
		str->fract.space_pressed = (str->fract.space_pressed == 0) ? 1 : 0;
	if (change == 1)
	{
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str);
	}
	return (0);
}
