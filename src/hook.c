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

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

int		key_move(int keycode, t_str *str)
{
	if (keycode == 34)
		init_str(str);
	if (keycode == 34)
		str->iso = 1;
	else if (keycode == 126 || keycode == 125)
		str->prm.move_y = (keycode == 126) ? str->prm.move_y - 100 :
				str->prm.move_y + 100;
	else if (keycode == 124 || keycode == 123)
		str->prm.move_x = (keycode == 123) ? str->prm.move_x - 100 :
				str->prm.move_x + 100;
	else if (keycode == 69 || keycode == 78)
		str->prm.zoom = (keycode == 69) ? str->prm.zoom + 1 :
				str->prm.zoom - 1;
	else if (keycode == 13 || keycode == 14)
		str->x_alfa = (keycode == 13) ? str->x_alfa + 0.10 :
				str->x_alfa - 0.10;
	else if (keycode == 1 || keycode == 2)
		str->y_alfa = (keycode == 1) ? str->y_alfa + 0.10 :
				str->y_alfa - 0.10;
	else if (keycode == 7 || keycode == 8)
		str->z_alfa = (keycode == 7) ? str->z_alfa + 0.10 :
			str->z_alfa - 0.10;
	mlx_clear_window(str->map.mlx, str->map.win);
	(keycode == 69 || keycode == 78) ? draw(str, 0) : draw(str, 1);
	return (0);
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
		init_str(str);
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str, 1);
	}
	else if (keycode == 115 || (keycode == 119 && str->prm.linesizey / 2 > 0))
	{
		str->prm.linesizex = (keycode == 115) ? str->prm.linesizex * 2 :
				str->prm.linesizex / 2;
		str->prm.linesizey = (keycode == 115) ? str->prm.linesizey * 2 :
				str->prm.linesizey / 2;
		str->x_center = str->length * str->prm.linesizex / 2;
		str->y_center = str->count_strings * str->prm.linesizey / 2;
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str, 1);
	}
	else if (keycode == 279)
	{
		str->color_style = (str->color_style > 4) ? 0 : str->color_style + 1;
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str, 1);
	}
	else
		key_move(keycode, str);
	return (0);
}

int		mouse_pressed(int button, int mousex, int mousey, t_str *str)
{
	if (button == 5 || button == 4)
	{
		str->prm.zoom = (button == 4) ? str->prm.zoom + 10 : str->prm.zoom - 10;
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str, 0);
	}
	else if ((button == 1 && str->prm.linesizey / 2 > 0) || button == 2)
	{
		str->prm.linesizex = (button == 2) ? str->prm.linesizex * 2 :
				str->prm.linesizex / 2;
		str->prm.linesizey = (button == 2) ? str->prm.linesizey * 2 :
				str->prm.linesizey / 2;
		mlx_clear_window(str->map.mlx, str->map.win);
		draw(str, 1);
	}
	return (0);
}
