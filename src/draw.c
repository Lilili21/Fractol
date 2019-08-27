/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:15:27 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 13:20:35 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_commands(t_str *str)
{
	(str->fractol->type == 1) ?
	mlx_string_put(str->map.mlx, str->map.win, 60, 30, 0x000000, "Julia") :
	(str->fractol->type == 2) ?
	mlx_string_put(str->map.mlx, str->map.win, 60, 30, 0x000000, "Mandelbrot") :
	mlx_string_put(str->map.mlx, str->map.win, 60, 30, 0x000000, "Turtle");
	mlx_string_put(str->map.mlx, str->map.win, 30, 60, 0x000000,
			"Iteration");
	mlx_string_put(str->map.mlx, str->map.win, 135, 60, 0x000000,
			ft_itoa(str->iteration));
	mlx_string_put(str->map.mlx, str->map.win, 60, 90, 0x000000, "Commands");
	mlx_string_put(str->map.mlx, str->map.win, 30, 120, 0x000000,
				   "change iteration  + -");
}

void		put_data(t_str *str, int x, int y, int color)
{
	long int cur_i;

	cur_i = x + y * (str->map.width);
	if (x < str->map.width && y < str->map.height && x > 0 && y > 0
		&& cur_i >= 0 && cur_i < (str->map.width) * (str->map.height))
		str->map.data[cur_i] = color;
}



int		key_pressed(int keycode, t_str *str)
{
	if (keycode == 53)
	{
		mlx_destroy_window(str->map.mlx, str->map.win);
		exit(0);
	}
	else if (keycode == 51)
	{
		str->fractol->type = (str->fractol->type == 1) ? 2 : 1;
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str);
	}
	else if (keycode == 115 || (keycode == 119) || keycode == 116 || keycode == 121)
	{
		if (keycode == 115)
			str->x_alfa++;
		if (keycode == 119)
			str->x_alfa--;
		if (keycode == 116)
			str->y_alfa++;
		if (keycode == 121)
			str->y_alfa--;

		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str);
	}
	return (0);
}

void	draw(t_str *str)
{
	str->map.img = mlx_new_image(str->map.mlx, str->map.width,
			str->map.height);
	str->map.data = (int *)mlx_get_data_addr(str->map.img,
			&(str->map.trash), &(str->map.trash), &(str->map.trash));
	if (str->fractol->type == 2)
		mandelbrot(str->fractol, str);
	else if (str->fractol->type == 1)
		julia(str->fractol, str);
	//else
	//	turtle(str);
	mlx_put_image_to_window(str->map.mlx, str->map.win, str->map.img, 0, 0);
	draw_commands(str);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}