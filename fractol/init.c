/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/04 19:24:38 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

t_mlx_env	*initialize_mlx(void)
{
	t_mlx_env	*env;

	env = malloc(sizeof(t_mlx_env));
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, SIZE, SIZE, "Fractal Viewer");
	env->image = mlx_new_image(env->mlx, SIZE, SIZE);
	env->data_addr = mlx_get_data_addr(env->image, &env->bpp, &env->line_size,
			&env->endian);
	return (env);
}

void	set_julia_params(t_fractal_params *params, char param)
{
	if (param == 'a')
	{
		params->julia_c.re = -0.4;
		params->julia_c.im = 0.6;
	}
	else if (param == 'b')
	{
		params->julia_c.re = -0.70176;
		params->julia_c.im = -0.3842;
	}
	else if (param == 'c')
	{
		params->julia_c.re = -0.8;
		params->julia_c.im = 0.156;
	}
	else
	{
		write(1, "./fractal mandelbrot|julia [a,b,c]\n", 40);
		exit(1);
	}
}

void	set_fractal_params(t_fractal_params *params, int argc, char **argv)
{
	params->type = argv[1];
	params->zoom = 1.0;
	params->offset_x = 0.0;
	params->offset_y = 0.0;
	params->max_iter = MAX_ITER;
	params->julia_c.re = -0.7;
	params->julia_c.im = 0.27015;
	if (argc == 3)
	{
		set_julia_params(params, *argv[2]);
	}
	if (argc >= 4)
	{
		write(1, "./fractal mandelbrot|julia [a,b,c]\n", 40);
		exit(1);
	}
}
