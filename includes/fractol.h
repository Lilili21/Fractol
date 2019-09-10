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
# define IMG_W 700
# define IMG_H 600
# define NB_THREADS 4
# define BUT_ESCAPE 53
# define BUT_DEL 51
# define BUT_UP 126
# define BUT_RIGHT 124
# define BUT_DOWN 125
# define BUT_LEFT 123
# define BUT_PLUS 24
# define BUT_MINUS 27
# define BUT_N_UP 91
# define BUT_N_RIGHT 88
# define BUT_N_DOWN 84
# define BUT_N_LEFT 86
# define BUT_N_PLUS 69
# define BUT_N_MINUS 78
# define BUT_1 18
# define BUT_2 19
# define BUT_3 20
# define BUT_4 21
# define BUT_5 23
# define BUT_6 22
# define BUT_7 26
# define BUT_SPACE 49
# define CHEKSUM2(a, b) (a*a + b*b)
# define CHEKDIF2(a, b) (a*a - b*b)
# define MOUSE_SC_UP 5
# define MOUSE_SC_DOWN 4
# define MOUSE_SC_LEFT 6
# define MOUSE_SC_RIGHT 7

typedef struct	s_map
{
	void		*img;
	int			*data;
	void		*mlx;
	void		*win;
	int			trash;
}				t_map;

typedef struct s_complex
{
	double 		re;
	double 		im;
}				t_complex;

typedef struct s_color
{
	double 		r_percent;
	double 		g_percent;
	double 		b_percent;
}				t_color;

typedef struct s_fractol
{
	int			type;
	int			iter;
	int 		color;
	int 		color_mad;
	int 		space_pressed;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	z;
	t_complex	xy;
	t_complex	zoom;

}				t_fractol;

typedef struct	s_str
{
	t_map		map;
	t_fractol	*fract;
}				t_str;

int		whoops(int i);
void	init_complex(double re, double im, t_complex *complex);
int 	ft_check_name(char *str);
int		ft_check_name2(char *fractol);
int		key_pressed(int keycode, t_str *str);
int		choose_col(float iter, float max_iter, int color_type, int mad);
char 	*color_scheme(int scheme, int color_p);
void	fractol(t_fractol	*f, t_str *str);
void	init_fr(t_fractol *f, int i);
int 	change_fractol(int keycode, t_str *str);
int		ft_close(void *param);
int		mouse_pressed(int button, int mousex, int mousey, t_str *str);
int		motion_notify(int mousex, int mousey, t_str *str);
void	put_data(t_str *str, int x, int y, int color);
void	draw(t_str *str);
#endif
