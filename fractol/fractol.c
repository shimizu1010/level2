/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/04 19:24:03 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

t_complex_values	calculate_initial_values(t_fractal_params *params, int x,
		int y)
{
	t_complex_values	values;

	values.z.im = 0;
	values.z.re = 0;
	values.c.im = 0;
	values.c.re = 0;
	if (ft_strcmp(params->type, "julia") == 0)
	{
		values.c = params->julia_c;
		values.z = init_complex(1.5 * (x - SIZE / 2) / (0.5 * params->zoom
					* SIZE), (y - SIZE / 2) / (0.5 * params->zoom * SIZE));
	}
	else if (ft_strcmp(params->type, "mandelbrot") == 0)
	{
		values.c = init_complex(1.5 * (x - SIZE / 2) / (0.5 * params->zoom
					* SIZE) + params->offset_x, (y - SIZE / 2) / (0.5
					* params->zoom * SIZE) + params->offset_y);
		values.z = init_complex(0, 0);
	}
	else
	{
		write(1, "./fractal mandelbrot|julia [a,b,c]\n", 40);
		exit(1);
	}
	return (values);
}

int	determine_color(int iteration, int max_iter)
{
	int	bright;
	int	color;

	if (iteration == max_iter)
	{
		return (0x000000);
	}
	else
	{
		bright = (iteration * 255 / max_iter);
		color = (bright & 255) << 16 | (bright & 128) << 8 | (bright & 64);
		return (color);
	}
}
