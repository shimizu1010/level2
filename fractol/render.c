/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/31 21:56:33 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_mlx_env *env, int x, int y, int color)
{
	int	index;

	index = (x * env->bpp / 8) + (y * env->line_size);
	if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
	{
		env->data_addr[index] = color & 255;
		env->data_addr[index + 1] = (color >> 8) & 255;
		env->data_addr[index + 2] = (color >> 16) & 255;
	}
}

void	render_pixel(t_mlx_env *mlx_env, t_fractal_params *params, int x, int y)
{
	t_complex_values	values;
	int					iteration;
	int					color;

	values = calculate_initial_values(params, x, y);
	iteration = iterate_fractal(values.z, values.c, params->max_iter);
	color = determine_color(iteration, params->max_iter);
	put_color_to_pixel(mlx_env, x, y, color);
}

void	calculate_and_render_fractal(t_mlx_env *mlx_env,
		t_fractal_params *params)
{
	int	x;
	int	y;

	x = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			render_pixel(mlx_env, params, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_env->mlx, mlx_env->window, mlx_env->image, 0,
		0);
}
