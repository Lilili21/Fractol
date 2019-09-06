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
# include <stdio.h>

# define WIN_WIDTH 1100
# define WIN_HEIGHT 600
# define IMG_WIDTH  700//1400
# define IMG_HEIGHT 600//1200
# define NB_THREADS 4
# define BUTTON_ESCAPE 53
# define BUTTON_DELETE 51
# define BUTTON_W 13
# define BUTTON_D 2
# define BUTTON_S 1
# define BUTTON_A 0
# define BUTTON_Q 12
# define BUTTON_E 14
# define BUTTON_B 11
# define BUTTON_C 8
# define BUTTON_ARROW_UP 126
# define BUTTON_ARROW_RIGHT 124
# define BUTTON_ARROW_DOWN 125
# define BUTTON_ARROW_LEFT 123
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_WHEEL_UP 5
# define MOUSE_WHEEL_DOWN 4

typedef struct	s_map
{
	void		*img;
	int		*data;
	void		*mlx;
	void		*win;
	int			trash;
}				t_map;

typedef struct	s_mouse
{
	int 		m_pressed;
	int			m_x;
	int			m_y;
}				t_mouse;

typedef struct s_complex
{
	double 		re;
	double 		im;
}				t_complex;

typedef struct s_fractol
{
	int			type;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	xy;
	t_complex	z;
	t_complex	zoom;
	int			iter;
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
	int			color_style;
	int			psychedelic;
	float		x_alfa;
	float		y_alfa;
	float		z_alfa;

}				t_str;



void	draw(t_str *str);
int		whoops(int i);
int		ft_close(void *param);
void	put_data(t_str *str, int x, int y, int color);
int		key_pressed(int keycode, t_str *str);
int		choose_col_b(float iter, float max_iter);
int		choose_col_g(float iter, float max_iter);
int		choose_col_y(float iter, float max_iter);
int		choose_col_r(float iter, float max_iter);
void	julia(t_fractol *julia, t_str *str);
void	initialize_julia(t_fractol *j);
void	mandelbrot(t_fractol	*m, t_str *str);
void	initialize_mandel(t_fractol *m);
void	rotate(t_fractol *fractol);
void	init_complex(double re, double im, t_complex *complex);
#endif
