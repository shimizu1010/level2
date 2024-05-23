/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/16 16:29:11 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_fractal(t_fractal *f)
{
	t_complex	c;
	t_complex	z;
	int			iteration;
	int			color;

	init_fractal_params(f, &c, &z);
	iteration = iterate_fractal(z, c, f->max_iter);
	if (iteration == f->max_iter)
		color = 0x000000;
	else
		color = iteration * 0x120B09;
	put_color_to_pixel(f, f->x, f->y, color);
}

void	draw_fractal(t_fractal *f)
{
	f->x = 0;
	while (f->x < SIZE)
	{
		f->y = 0;
		while (f->y < SIZE)
		{
			calculate_fractal(f);
			f->y++;
		}
		f->x++;
	}
}

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(f->mlx, f->window);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		f->zoom *= 1.1;
	}
	else if (button == 5)
	{
		f->zoom *= 0.9;
	}
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	return (0);
}

int	close_hook(t_fractal *f)
{
	mlx_destroy_window(f->mlx, f->window);
	exit(0);
	return (0);
}
