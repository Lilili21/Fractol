/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:38:25 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 13:39:58 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rotate(t_str *str, int i)
{
	str->xyz[i].x -= str->x_center;
	str->xyz[i].y -= str->y_center;
	str->xyz_tmp[i].x =
			cos(str->y_alfa) * cos(str->z_alfa) * str->xyz[i].x +
			cos(str->y_alfa) * sin(str->z_alfa) * str->xyz[i].y +
			sin(str->y_alfa) * str->xyz[i].z * str->prm.zoom;
	str->xyz_tmp[i].y =
			(-sin(str->x_alfa) * sin(str->y_alfa) * cos(str->z_alfa) -
			cos(str->x_alfa) * sin(str->z_alfa)) * str->xyz[i].x +
			(cos(str->x_alfa) * cos(str->z_alfa) - sin(str->x_alfa) *
			sin(str->y_alfa) * sin(str->z_alfa)) * str->xyz[i].y +
			sin(str->x_alfa) * cos(str->y_alfa) * str->xyz[i].z * str->prm.zoom;
	str->xyz_tmp[i].z =
			(-sin(str->y_alfa) * cos(str->x_alfa) * cos(str->z_alfa) +
			sin(str->x_alfa) * sin(str->z_alfa)) * str->xyz[i].x +
			(-sin(str->y_alfa) * cos(str->x_alfa) * sin(str->z_alfa) -
			sin(str->x_alfa) * cos(str->z_alfa)) * str->xyz[i].y +
			cos(str->x_alfa) * cos(str->y_alfa) * str->xyz[i].z * str->prm.zoom;
	str->xyz[i].x += str->x_center;
	str->xyz[i].y += str->y_center;
}

void	find_centr(t_str *str)
{
	int i;

	i = str->count_strings / 2 * str->length + str->length / 2;
	str->delta_x = str->xyz[i].x - (double)str->map.width_img / 2
			- str->prm.move_x - str->x_center;
	str->delta_y = str->xyz[i].y - (double)str->map.height_img / 2
			- str->prm.move_y - str->y_center;
}

void	normalize(t_str *str, int i)
{
	str->xyz_tmp[i].x -= str->delta_x;
	str->xyz_tmp[i].y -= str->delta_y;
}
