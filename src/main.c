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

t_str		init_str(t_str *str, char *fractol)
{
	str->fractol = (t_fractol *)malloc(sizeof(t_fractol));
	str->fractol->type = ft_strequ(fractol, "Julia") ? 1 :
			(ft_strequ(fractol, "Mandelbrot") ? 2 : ft_strequ(fractol, "Turtle") ?
			3 : 4);
	if (str->fractol->type == 1)
		initialize_julia(str->fractol);
	else
		initialize_mandel(str->fractol);
	str->x_alfa = 0.1;
	str->y_alfa = 0.0;
	str->z_alfa = 0.0;
	return (*str);
}

void		draw_str(t_str str)
{
	str.map.mlx = mlx_init();
	str.map.win = mlx_new_window(str.map.mlx, WIN_WIDTH, WIN_HEIGHT,
			"Fractol");
	draw(&str);
	mlx_hook(str.map.win, 2, 0, key_pressed, &str);
	//mlx_hook(str.map.win, 4, 0, mouse_pressed, &str);
	mlx_hook(str.map.win, 17, 0, &ft_close, NULL);
	mlx_loop(str.map.mlx);
}

int			whoops(int i)
{
	if (i == 1)
		ft_putstr_fd("usage: fractol [fractals]\n fractals:\n"
			   "-->Mandelbrot\n -->Julia\n -->Turtle\n -->Island\n", 2);
	else if (i == 2)
		ft_putstr_fd("malloc problem", 2);
	return (-1);
}

int 		ft_check_name(char *str)
{
	if (ft_strequ(str, "Julia") || ft_strequ(str, "Mandelbrot") ||
	ft_strequ(str, "Turtle") || ft_strequ(str, "Island"))
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_str	str;

	if (argc != 2 || !ft_check_name(argv[1]))
		return (whoops(1));
	init_str(&str, argv[1]);
	draw_str(str);
	return (0);
}

