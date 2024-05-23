/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/16 16:46:05 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_fractal *f, int x, int y, int color)
{
	int	i;

	i = (x * f->bpp / 8) + (y * f->line_size);
	if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
	{
		f->data_addr[i] = color;
		f->data_addr[++i] = color >> 8;
		f->data_addr[++i] = color >> 16;
	}
}

void	init_fractal_params(t_fractal *f, t_complex *c, t_complex *z)
{
	if (strcmp(f->type, "julia") == 0)
	{
		c->re = f->c_re;
		c->im = f->c_im;
		z->re = 1.5 * (f->x - SIZE / 2) / (0.5 * f->zoom * SIZE);
		z->im = (f->y - SIZE / 2) / (0.5 * f->zoom * SIZE);
	}
	else
	{
		c->re = f->x / f->zoom + f->offset_x;
		c->im = f->y / f->zoom + f->offset_y;
		z->re = 0;
		z->im = 0;
	}
}

int	iterate_fractal(t_complex z, t_complex c, int max_iter)
{
	int		iteration;
	double	x_temp;

	iteration = 0;
	while (iteration < max_iter && (z.re * z.re + z.im * z.im) < 4)
	{
		x_temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = x_temp;
		iteration++;
	}
	return (iteration);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
