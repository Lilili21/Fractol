/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:14:01 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 13:14:28 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_data(t_str *str, int x, int y, int color)
{
	long int cur_i;

	cur_i = x + y * (str->map.width_img);
	if (x < str->map.width_img && y < str->map.height_img && x > 0 && y > 0
		&& cur_i >= 0 && cur_i < (str->map.width_img) * (str->map.height_img))
		str->map.data[cur_i] = color;
}

void		horizontal(t_str *str, int k)
{
	int		err;
	int		i;

	i = 0;
	err = str->prm.dx / 2;
	while (i < str->prm.dx)
	{
		str->xyz_tmp[k].x += str->prm.incrx;
		err += str->prm.dy;
		if (err > str->prm.dx)
		{
			err -= str->prm.dx;
			str->xyz_tmp[k].y += str->prm.incry;
		}
		put_data(str, (int)str->xyz_tmp[k].x, (int)str->xyz_tmp[k].y,
				str->xyz_tmp[k].color);
		i++;
	}
}

void		incline(t_str *str, int k)
{
	int		err;
	int		i;

	i = 0;
	err = str->prm.dy / 2;
	while (i < str->prm.dy)
	{
		str->xyz_tmp[k].y += str->prm.incry;
		err += str->prm.dx;
		if (err >= str->prm.dy)
		{
			err -= str->prm.dy;
			str->xyz_tmp[k].x += str->prm.incrx;
		}
		put_data(str, (int)str->xyz_tmp[k].x, (int)str->xyz_tmp[k].y,
				str->xyz_tmp[k].color);
		i++;
	}
}

void		iso(t_str *str, int i)
{
	double previous_x;
	double previous_y;

	previous_x = str->xyz_tmp[i].x;
	previous_y = str->xyz_tmp[i].y;
	str->xyz_tmp[i].x = (previous_x - previous_y) * cos(0.523599);
	str->xyz_tmp[i].y = -str->xyz_tmp[i].z + (previous_x + previous_y)
		* sin(0.523599);
}

void		draw_img(t_str *str, int i, int j)
{
	rotate(str, i);
	rotate(str, j);
	if (str->iso == 1)
	{
		iso(str, i);
		iso(str, j);
	}
	normalize(str, i);
	normalize(str, j);
	str->prm.incrx = (str->xyz_tmp[j].x > str->xyz_tmp[i].x) ? 1 : -1;
	str->prm.incry = (str->xyz_tmp[j].y > str->xyz_tmp[i].y) ? 1 : -1;
	str->prm.dx = (int)fabs(str->xyz_tmp[j].x - str->xyz_tmp[i].x);
	str->prm.dy = (int)fabs(str->xyz_tmp[j].y - str->xyz_tmp[i].y);
	if (str->prm.dx > str->prm.dy)
		horizontal(str, i);
	else
		incline(str, i);
}
