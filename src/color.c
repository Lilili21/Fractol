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

char			*color_scheme(int scheme, int color_p)
{
	int		i;
	char	*t;
	char	*result;

	i = 1;
	while (color_p >= 10)
	{
		color_p /= 10;
		i++;
	}
	t = (color_p == 0) ? "" : ft_itoa(i);
	if (scheme == 0)
		result = ft_strjoin("red ", t);
	else if (scheme == 1)
		result = ft_strjoin("green ", t);
	else if (scheme == 2)
		result = ft_strjoin("blue ", t);
	else if (scheme == 3)
		result = ft_strjoin("dark ", t);
	else
		result = ft_strjoin("mad ", t);
	if (color_p != 0)
		free(t);
	return (result);
}

static t_color	*color_percent(int color_type)
{
	t_color *color;

	color = (t_color *)malloc(sizeof(t_color));
	if (color_type == 4)
		return (color);
	color->r_percent = (color_type == 3) ? 0.33 : 0;
	color->g_percent = (color_type == 3) ? 0.33 : 0;
	color->b_percent = (color_type == 3) ? 0.33 : 0;
	if (color_type == 0)
		color->r_percent = 0.33;
	if (color_type == 1)
		color->g_percent = 0.33;
	if (color_type == 2)
		color->b_percent = 0.33;
	return (color);
}

int				choose_col(t_fractol *f)
{
	int			r;
	int			g;
	int			b;
	t_color		*color;
	double		t;

	if (f->i >= f->iter)
		return (0);
	color = color_percent(f->color);
	t = (double)f->i / f->iter;
	if (f->color != 4)
	{
		r = (int)(f->color_mad * t * color->r_percent * 255);
		g = (int)(f->color_mad * t * color->g_percent * 255);
		b = (int)(f->color_mad * t * color->b_percent * 255);
	}
	else
	{
		r = (int)(COLOR(fmod((double)f->ps_time * t * 0.99, 2 * PI)));
		g = (int)(COLOR(fmod((double)f->ps_time * t * 0.66, 2 * PI)));
		b = (int)(COLOR(fmod((double)f->ps_time * t * 0.33, 2 * PI)));
	}
	free(color);
	return (r << 16 | g << 8 | b);
}
