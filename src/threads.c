/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:36:22 by gfoote            #+#    #+#             */
/*   Updated: 2019/09/13 13:36:24 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*render_quads(void *args)
{
	t_complex	start;
	t_complex	finish;
	t_str		*str;

	str = (t_str *)args;
	start.re = -1;
	finish.re = IMG_W;
	start.im = (double)IMG_H / NB_THREADS * str->intr - 1;
	finish.im = (double)IMG_H / NB_THREADS * (str->intr + 1);
	str->img = mlx_new_image(str->map.mlx, IMG_W, (IMG_H / NB_THREADS));
	str->data = (int *)mlx_get_data_addr(str->img, &(str->map.trash),
			&(str->map.trash), &(str->map.trash));
	if (str->fract.type != 7)
		fractol(&str->fract, str, start, finish);
	else
		carpet(&str->fract, str, start, finish);
	pthread_exit(0);
}
