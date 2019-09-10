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

int		key_esc_del_iter(int keycode, t_str *str)
{
	if (keycode == BUT_ESCAPE)
	{
		free(str->fract);
		mlx_destroy_window(str->map.mlx, str->map.win);
		exit(0);
	}
	else if (keycode == BUT_DELETE)
	{
		str->fract->type = (str->fract->type == 6) ? 1 : ++str->fract->type;
		(str->fract->type == 1) ? init_fr(str->fract, 0) :
		init_fr(str->fract, 1);
	}
	else if (keycode == BUT_PLUS)
		str->fract->iter = (str->fract->iter < 490) ?
		str->fract->iter + 10 : 500;
	else if (keycode == BUT_MINUS)
		str->fract->iter = (str->fract->iter > 10) ? str->fract->iter - 10 : 0;
	mlx_clear_window(str->map.mlx, str->map.win);
	draw(str);
	return (0);
}

int		key_color(int keycode, t_str *str)
{
	if (keycode == BUT_LEFT)
		str->fract->color = (str->fract->color == 0) ? 4 : --str->fract->color;
	else if (keycode == BUT_RIGHT)
		str->fract->color = (str->fract->color == 4) ? 0 : ++str->fract->color;
	else if (keycode == BUT_DOWN)
		str->fract->color_mad = (str->fract->color_mad / 10 < 1) ? 1 :
		str->fract->color_mad / 10;
	else
		str->fract->color_mad = (str->fract->color_mad * 10 > 10000000) ?
		10000000 : str->fract->color_mad * 10;
	mlx_clear_window(str->map.mlx, str->map.win);
	draw(str);
	return (0);
}

int		key_move(int keycode, t_str *str)
{
	if (keycode == BUT_N_LEFT)
	{
		str->fract->min.re += 0.01;
		str->fract->max.re += 0.01;
	}
	else if (keycode == BUT_N_RIGHT)
	{
		str->fract->min.re -= 0.01;
		str->fract->max.re -= 0.01;
	}
	else if (keycode == BUT_N_DOWN)
	{
		str->fract->min.im -= 0.01;
		str->fract->max.im -= 0.01;
	}
	else
	{
		str->fract->min.im += 0.01;
		str->fract->max.im += 0.01;
	}
	mlx_clear_window(str->map.mlx, str->map.win);
	draw(str);
	return (0);
}

int		key_zoom(int keycode, t_str *str)
{
	if (keycode == BUT_N_MINUS)
	{
		str->fract->min.re *= 1.1;
		str->fract->max.re *= 1.1;
		str->fract->min.im *= 1.1;
		str->fract->max.im *= 1.1;
	}
	else
	{
		str->fract->min.re /= 1.1;
		str->fract->max.re /= 1.1;
		str->fract->min.im /= 1.1;
		str->fract->max.im /= 1.1;
	}
	init_complex((str->fract->max.re - str->fract->min.re) / IMG_W,
				 (str->fract->max.im - str->fract->min.im) / IMG_H, &str->fract->zoom);
	mlx_clear_window(str->map.mlx, str->map.win);
	draw(str);
	return (0);
}

int		key_pressed(int keycode, t_str *str)
{
	if (keycode == BUT_ESCAPE || keycode == BUT_DELETE ||
	keycode == BUT_PLUS || keycode == BUT_MINUS)
		return (key_esc_del_iter(keycode, str));
	else if (keycode == BUT_RIGHT || keycode == BUT_LEFT ||
	keycode == BUT_UP || keycode == BUT_DOWN)
		return (key_color(keycode, str));
	else if (keycode == BUT_N_UP || keycode == BUT_N_DOWN
			|| keycode == BUT_N_RIGHT || keycode == BUT_N_LEFT)
		return (key_move(keycode, str));
	else if (keycode == BUT_N_MINUS || keycode == BUT_N_PLUS)
		return (key_zoom(keycode, str) == 1);
	else if (str->fract->type == 1 && keycode == BUT_SPACE)
	{
		str->fract->space_pressed = (str->fract->space_pressed == 0) ? 1 : 0;
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str);
	}
	printf("%i\n",str->fract->space_pressed);
	return (0);
}
