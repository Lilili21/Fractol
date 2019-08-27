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

void	mandelbrot(t_fractol	*mandelbrot, t_str *str)
{
	float tmp;
	int i;
	float zr;
	float zi;
	float c_imaginary;
	float c_real;
	float x1, y1;

	mandelbrot->c_real = - 2.6;
	mandelbrot->c_imaginary = -2.6;
	mandelbrot->zoom = 0.2;

	for (int y = 0; y < str->map.height; ++y)
	{
		for (int x = 0; x < str->map.width; ++x)
		{
			c_real = x * 1.0 / ( str->map.width * str->fractol->zoom) + mandelbrot->c_real;
			c_imaginary = y * 1.0 / ( str->map.height * str->fractol->zoom) + mandelbrot->c_imaginary;
			i = 0;
			zr = 0;
			zi = 0;
			while (i < str->iteration && zr * zr + zi * zi < 4)
			{
				tmp = zr;
				zr = zr * zr - zi * zi + c_real;
				zi = 2 * tmp * zi + c_imaginary;
				i++;
			}
			x1 -= str->map.width/2 * 0.1;
			y1 -= str->map.height/2 * 0.1;
			x1 = cos(str->y_alfa) * cos(str->z_alfa) * x + cos(str->y_alfa) * sin(str->z_alfa) * y;
			y1 = (-sin(str->x_alfa) * sin(str->y_alfa) * cos(str->z_alfa) -
				  cos(str->x_alfa) * sin(str->z_alfa)) * x + (cos(str->x_alfa) * cos(str->z_alfa) - sin(str->x_alfa) * sin(str->y_alfa) * sin(str->z_alfa)) * y;
			x1 += str->map.width/2 * 0.1;
			y1 +=  str->map.height/2 * 0.1;
			put_data(str, x1, y1, choose_col(str, i));
		}
	}
}
