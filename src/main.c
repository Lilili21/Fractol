/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:49:17 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 12:49:35 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		init_str(t_str *str, char *fractol)
{
	str->fract.type = ft_check_name2(fractol);
	if (str->fract.type == -1)
		return (whoops(1));
	str->fract.color = 1;
	str->fract.color_mad = 10000;
	str->fract.ps = 0;
	str->fract.ps_time = 0;
	if (str->fract.type == 7)
	{
		str->fract.iter = 3;
		init_carpet(&str->fract);
	}
	else
		(str->fract.type == 1) ? init_fr(&str->fract, 0)
		: init_fr(&str->fract, 1);
	str->fract.space_pressed = 0;
	return (1);
}

static void		draw_str(t_str str)
{
	str.map.mlx = mlx_init();
	str.map.win = mlx_new_window(str.map.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	draw(&str);
	mlx_hook(str.map.win, 2, 0, key_pressed, &str);
	mlx_hook(str.map.win, 6, 0, motion_notify, &str);
	mlx_hook(str.map.win, 4, 0, mouse_pressed, &str);
	mlx_hook(str.map.win, 17, 0, &ft_close, NULL);
	mlx_loop_hook(str.map.mlx, loop_hook, &str);
	mlx_loop(str.map.mlx);
}

int				main(int argc, char **argv)
{
	t_str	str;

	if (argc != 2 || !ft_check_name(argv[1]))
		return (whoops(1));
	if (init_str(&str, argv[1]) == -1)
		return (1);
	draw_str(str);
	return (0);
}
