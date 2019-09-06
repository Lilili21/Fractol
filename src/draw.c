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

void	draw_commands(t_str *str)
{
	mlx_string_put(str->map.mlx, str->map.win, 10, 5, 0xFFFFFF, "Fractol type: ");
	(str->fractol->type == 1) ?
	mlx_string_put(str->map.mlx, str->map.win, 160, 5, 0xFFFFFF, "Julia") :
	(str->fractol->type == 2) ?
	mlx_string_put(str->map.mlx, str->map.win, 150, 5, 0xFFFFFF, "Mandelbrot") :
	mlx_string_put(str->map.mlx, str->map.win, 150, 5, 0xFFFFFF, "Turtle");
	mlx_string_put(str->map.mlx, str->map.win, 10, 35, 0xFFFFFF, "Change type:   Numlock keys");
	mlx_string_put(str->map.mlx, str->map.win, 10, 65, 0xFFFFFF, "Iterations: ");
	mlx_string_put(str->map.mlx, str->map.win, 10, 95, 0xFFFFFF,
				   "Change iteration: + -");
	mlx_string_put(str->map.mlx, str->map.win, 10, 125, 0xFFFFFF, "Color scheme: ");
	mlx_string_put(str->map.mlx, str->map.win, 10, 155, 0xFFFFFF, "Change color: + -");
}

void		put_data(t_str *str, int x, int y, int color)
{
	long int cur_i;

	cur_i = x + y * (IMG_WIDTH);
	if (x < IMG_WIDTH && y < IMG_HEIGHT && x > 0 && y > 0
		&& cur_i >= 0 && cur_i < IMG_WIDTH * IMG_HEIGHT)
		str->map.data[cur_i] = color;
}

int		key_pressed(int keycode, t_str *str)
{
	if (keycode == BUTTON_ESCAPE)
	{
		mlx_destroy_window(str->map.mlx, str->map.win);
		exit(0);
	}
	else if (keycode == BUTTON_DELETE)
	{
		str->fractol->type = (str->fractol->type == 1) ? 2 : 1;
		(str->fractol->type == 1) ? initialize_julia(str->fractol) :
		initialize_mandel(str->fractol);
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str);
	}
	/*else if (keycode == 115 || (keycode == 119) || keycode == 116 || keycode == 121)
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
	}*/
	return (0);
}

void	draw_frame(t_str *str)
{
	int i;

	i = -1;
	while (i < IMG_WIDTH)
	{
		str->map.data[++i] = "0x00FF00";
		i += IMG_WIDTH * (IMG_HEIGHT - 1);
		str->map.data[i] = "0x00FF00";
		i -= IMG_WIDTH * (IMG_HEIGHT - 1);
	}
	i = 0;
	while (i < IMG_HEIGHT * IMG_WIDTH)
	{
		str->map.data[i] = "0x00FF00";
		i += IMG_WIDTH - 1;
		str->map.data[i] = "0x00FF00";
		i++;
	}
}

void	draw(t_str *str)
{
	str->map.img = mlx_new_image(str->map.mlx, IMG_WIDTH , IMG_HEIGHT);
	str->map.data = (int *)mlx_get_data_addr(str->map.img,
											 &(str->map.trash), &(str->map.trash), &(str->map.trash));
	if (str->fractol->type == 2)
		mandelbrot(str->fractol, str);
	else
		julia(str->fractol, str);
	//else
	//	turtle(str);
	draw_frame(str);
	draw_commands(str);
	mlx_put_image_to_window(str->map.mlx, str->map.win, str->map.img, 400, 0);

}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}
