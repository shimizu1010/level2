/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/16 16:46:25 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define SIZE 800
# define MAX_ITER 100
# define ESC_KEY 53

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*data_addr;
	int		bpp;
	int		line_size;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	char	*type;
	double	c_re;
	double	c_im;
	int		x;
	int		y;
}			t_fractal;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

void		initialize(t_fractal *f);
void		set_fractal_params(t_fractal *f, int argc, char **argv);
void		set_hooks(t_fractal *f);
void		draw_fractal(t_fractal *f);
int			key_hook(int keycode, t_fractal *f);
int			mouse_hook(int button, int x, int y, t_fractal *f);
int			close_hook(t_fractal *f);
void		init_fractal_params(t_fractal *f, t_complex *c, t_complex *z);
int			iterate_fractal(t_complex z, t_complex c, int max_iter);
void		put_color_to_pixel(t_fractal *f, int x, int y, int color);
double		ft_atof(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(char c);

#endif
