/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/04 19:23:32 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx_env			*mlx_env;
	t_context			ctx;
	t_fractal_params	params;

	if (argc < 2)
	{
		write(1, "./fractal mandelbrot|julia [a,b,c]\n", 40);
		return (1);
	}
	mlx_env = initialize_mlx();
	set_fractal_params(&params, argc, argv);
	ctx.mlx_env = mlx_env;
	ctx.params = &params;
	calculate_and_render_fractal(mlx_env, &params);
	mlx_key_hook(mlx_env->window, handle_keypress, mlx_env);
	mlx_mouse_hook(mlx_env->window, (int (*)())handle_mouse, &ctx);
	mlx_hook(mlx_env->window, 17, 0, handle_close, mlx_env);
	mlx_loop(mlx_env->mlx);
	return (0);
}
