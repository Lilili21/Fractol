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

static void 	init_thread()
{
	pthread_t thread_id;

	printf("Before Thread\n");

	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}

static void		init_str(t_str *str, char *fractol)
{
	str->fract = (t_fractol *)malloc(sizeof(t_fractol));
	str->fract->type = ft_check_name2(fractol);
	str->fract->color = 2;
	str->fract->color_mad = 10;
	(str->fract->type == 1) ? init_fr(str->fract, 0)
	: init_fr(str->fract, 1);
	str->fract->space_pressed = 0;
}

static void		draw_str(t_str str)
{
	str.map.mlx = mlx_init();
	str.map.win = mlx_new_window(str.map.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	draw(&str);
	mlx_hook(str.map.win, 2, 0, key_pressed, &str);
	mlx_hook(str.map.win, 6, 0, &motion_notify, &str);
	mlx_hook(str.map.win, 4, 0, mouse_pressed, &str);
	mlx_hook(str.map.win, 17, 0, &ft_close, NULL);
	mlx_loop(str.map.mlx);
}

int				main(int argc, char **argv)
{
	t_str	str;

	if (argc != 2 || !ft_check_name(argv[1]))
		return (whoops(1));
	init_str(&str, argv[1]);
	//init_thread(&str);
	draw_str(str);
	return (0);
}
