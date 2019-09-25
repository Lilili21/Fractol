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

static void		ml(t_str *str, int a, int b, char *text)
{
	int			color;

	if (str->fract.color == 0)
		color = 0xFF6666;
	else if (str->fract.color == 1)
		color = 0x99FF99;
	else if (str->fract.color == 2)
		color = 0x6060A0;
	else
		color = 0x808080;
	if (b == 5 || b == 65 || b == 125 || (b == 245 && str->fract.space_pressed)
	|| (b == 185 && str->fract.ps))
		mlx_string_put(str->map.mlx, str->map.win, a, b, 0xFFFFFF, text);
	else
		mlx_string_put(str->map.mlx, str->map.win, a, b, color, text);
}

void			put_data(t_str *str, int x, int y, int color)
{
	long int cur_i;

	cur_i = x + y * (IMG_W);
	if (x < IMG_W && y < (IMG_H / NB_THREADS) && x >= 0 && y >= 0
	&& cur_i >= 0 && cur_i < IMG_W * (IMG_H / NB_THREADS))
		str->data[cur_i] = color;
}

static char		*name_fr(int i)
{
	if (i == 1)
		return ("Julia");
	else if (i == 2)
		return ("Mandelbrot");
	else if (i == 3)
		return ("Burning Ship");
	else if (i == 4)
		return ("Mandelbar");
	else if (i == 5)
		return ("Celtic Mandelbrot");
	else if (i == 6)
		return ("Celtic Mandelbar");
	else
		return ("Carpet");
}

void			draw_commands(t_str *str)
{
	char		*tmp;

	ml(str, 10, 5, "Fractol type: ");
	ml(str, 150, 5, name_fr(str->fract.type));
	ml(str, 10, 35, "Change:  Numbers & Backspace");
	ml(str, 10, 65, "Iterations: ");
	tmp = ft_itoa(str->fract.iter);
	ml(str, 150, 65, tmp);
	free(tmp);
	ml(str, 10, 95, "Change: + -");
	ml(str, 10, 125, "Color scheme: ");
	tmp = (str->fract.type == 7) ? color_scheme(str->fract.color, 0) :
		color_scheme(str->fract.color, str->fract.color_mad);
	ml(str, 150, 125, tmp);
	free(tmp);
	ml(str, 10, 155, "Change: Up Down Left Right");
	if (str->fract.ps == 0 && str->fract.type != 7)
		ml(str, 10, 185, "To start psychedelic colors press P");
	else if (str->fract.ps != 0 && str->fract.type != 7)
		ml(str, 10, 185, "To stop psychedelic colors press P");
	ml(str, 10, 215, "To change position & zoom use Numlock");
	if (str->fract.type == 1 && str->fract.space_pressed == 1)
		ml(str, 10, 245, "To stop changing C press SPACE");
	else if (str->fract.type == 1 && str->fract.space_pressed == 0)
		ml(str, 10, 245, "To change C press SPACE");
}

void			draw(t_str *str)
{
	int			i;
	pthread_t	tids[NB_THREADS];
	t_str		sstr[NB_THREADS];

	i = -1;
	while (++i < NB_THREADS)
	{
		ft_memcpy((void *)&sstr[i], (void*)str, sizeof(t_str));
		sstr[i].intr = i;
		pthread_create(&tids[i], NULL, render_quads, (void *)&sstr[i]);
	}
	i = -1;
	while (++i < NB_THREADS)
	{
		pthread_join(tids[i], NULL);
		mlx_put_image_to_window(str->map.mlx, str->map.win, sstr[i].img,
		sstr[i].start.re + 400, i * ((IMG_H / NB_THREADS)));
	}
	draw_commands(str);
}
