/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:17:27 by gfoote            #+#    #+#             */
/*   Updated: 2019/08/27 17:17:28 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia(t_fractol	*julia, t_str *str)
{
	float tmp;
	int i;
	float zr;
	float zi;
	float x1;
	float y1;

	julia->c_real = -0.8;
	julia->c_imaginary = 0.156;
	julia->zoom = 1;

	for (int x = 0; x < str->map.width; x++)
	{
		for (double y = 0; y < str->map.height; y++)
		{
			zr = 1.5 * (x - (int)(str->map.width / 2)) / (0.5 * julia->zoom * str->map.width);
			zi = 1.0 * (y - (int)(str->map.height / 2)) / (0.5 * julia->zoom * str->map.height);
			i = str->iteration;
			while (zr * zr + zi * zi < 4 && i > 1)
			{
				tmp = zr * zr - zi * zi + julia->c_real;
				zi = 2.0 * zr * zi + julia->c_imaginary;
				zr = tmp;
				i -= 1;
			}
			x1 -= str->map.width/2 * 0.1;
			y1 -= str->map.height/2 * 0.1;
			x1 = cos(str->y_alfa) * cos(str->z_alfa) * x + cos(str->y_alfa) * sin(str->z_alfa) * y;
			y1 = (-sin(str->x_alfa) * sin(str->y_alfa) * cos(str->z_alfa) -
				  cos(str->x_alfa) * sin(str->z_alfa)) * x + (cos(str->x_alfa) * cos(str->z_alfa) - sin(str->x_alfa) * sin(str->y_alfa) * sin(str->z_alfa)) * y;
			x1 += str->map.width/2 * 0.1;
			y1 +=  str->map.height/2 * 0.1;
			put_data(str, x1, y1,  choose_col(str, i));
		}
	}
}
