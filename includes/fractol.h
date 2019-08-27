/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:29:45 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/11 17:41:49 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct	s_map
{
	void		*img;
	int			*data;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			trash;
}				t_map;

typedef struct	s_mouse
{
	int 		m_pressed;
	int			m_x;
	int			m_y;
}				t_mouse;

typedef struct s_fractol
{
	int			type;
	float 		c_real;
	float 		c_imaginary;
	float		zoom;
	int			x;
	int 		y;
	float 		t_rotate;
}				t_fractol;

typedef struct s_color
{
	int			cent;
	int			wid;
	float		r_freq;
	float		g_freq;
	float		b_freq;
	float		r_phase;
	float		g_phase;
	float		b_phase;
}				t_color;

typedef struct	s_str
{
	t_map		map;
	t_mouse		mouse;
	t_fractol	*fractol;
	t_color		c;
	int 		iteration;
	size_t		iter_lim;
	int 	color_style;
	int		psychedelic;
	float x_alfa;
	float y_alfa;
	float z_alfa;

}				t_str;



void	draw(t_str *str);
int		whoops(int i);
int		ft_close(void *param);
int		key_pressed(int keycode, t_str *str);
int		choose_col(t_str *str, float iter);
void	julia(t_fractol	*julia, t_str *str);
void	mandelbrot(t_fractol	*mandelbrot, t_str *str);
#endif
