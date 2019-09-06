/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:35:45 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/15 16:35:47 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose_col_b(float iter, float max_iter)
{
	int		r;
	int		g;
	int		b;
	double t;

	if (iter >=max_iter)
		return (0);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (r << 16 | g << 8 | b);
}

int		choose_col_g(float iter, float max_iter)
{
	int		r;
	int		g;
	int		b;
	double t;

	if (iter >=max_iter)
		return (0);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	b = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	g = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (r << 16 | g << 8 | b);
}

int		choose_col_y(float iter, float max_iter)
{
	int		r;
	int		g;
	int		b;
	double t;

	if (iter >=max_iter)
		return (0);
	t = (double)iter / max_iter;
	b = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(8.5 * pow((1 - t), 3) * t * 255);;
	r = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (r << 16 | g << 8 | b);
}

int		choose_col_r(float iter, float max_iter)
{
	int		r;
	int		g;
	int		b;
	double t;

	if (iter >=max_iter)
		return (0);
	t = (double)iter / max_iter;
	g = (int)(9 * (1 - t) * pow(t, 3) * 255);
	b = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	r = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (r << 16 | g << 8 | b);
}

