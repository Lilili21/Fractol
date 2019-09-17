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
	start.re = 0;
	finish.re = IMG_W;
	start.im = IMG_H / NB_THREADS * str->intr - 1;
	finish.im = IMG_H / NB_THREADS * (str->intr + 1);
	fractol(str->fract, str, start, finish);
	pthread_exit(0);
}
