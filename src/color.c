/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:35:45 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/15 16:35:47 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	setup_color(t_str *str)
{
	str->color_style = 0;
	str->c.cent = 127;
	str->c.wid = 128;
	str->c.r_freq = 0.33;
	str->c.g_freq = 0.33;
	str->c.b_freq = 0.33;
	str->c.r_phase = 0.00;
	str->c.g_phase = (2 * M_PI) / 3;
	str->c.b_phase = (4 * M_PI) / 3;
	str->psychedelic = 0;
}

void	toggle_palette(t_str *str)
{
	str->color_style = (str->color_style + 1) % 4;
	if (str->color_style == 0)
	{
		str->c.r_freq = 0.33;
		str->c.g_freq = 0.33;
		str->c.b_freq = 0.33;
	}
	if (str->color_style == 1)
	{
		str->c.r_freq = 0.33;
		str->c.g_freq = 0.33;
		str->c.b_freq = 0.00;
	}
	if (str->color_style == 2)
	{
		str->c.r_freq = 0.33;
		str->c.g_freq = 0.00;
		str->c.b_freq = 0.33;
	}
	if (str->color_style == 3)
	{
		str->c.r_freq = 0.00;
		str->c.g_freq = 0.33;
		str->c.b_freq = 0.33;
	}
}

void	color_surprise(t_str *str)
{
	str->c.r_freq = rand() % 10;
	str->c.g_freq = rand() % 10;
	str->c.b_freq = rand() % 10;
}

void	psychedelic_surprise(t_str *str)
{
	str->c.r_phase = rand() % 20;
	str->c.g_phase = rand() % 20;
	str->c.b_phase = rand() % 20;
}

/*
** choose_col()
** Let's use some math magic to generate some pretty colors!
** By using a sin wave and shifting the frequency and phase of r, g, b
** color components we can generate regular repeating color gradients!
**
** The center of our color range is 127 (because 255 is max)
** Thus the width of our color range is 128 (if we want rainbow effects)
** Heavily inspired by: https://krazydad.com//tutorials/makecolors.php
*/

int		choose_col(t_str *str, float iter)
{
	int		r;
	int		g;
	int		b;
	t_color	c;

	c = str->c;
	if (iter >= str->iter_lim)
		return (0);
	else
	{
		r = sin(fmod(c.r_freq * iter + c.r_phase, 2 * M_PI)) * c.wid + c.cent;
		g = sin(fmod(c.g_freq * iter + c.g_phase, 2 * M_PI)) * c.wid + c.cent;
		b = sin(fmod(c.b_freq * iter + c.b_phase, 2 * M_PI)) * c.wid + c.cent;
		return (r << 16 | g << 8 | b);
	}
}

