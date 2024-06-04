/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/31 21:56:16 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, t_mlx_env *mlx_env)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(mlx_env->mlx, mlx_env->window);
		exit(0);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_context *ctx)
{
	(void)x;
	(void)y;
	if (button == 4)
		ctx->params->zoom *= 1.2;
	else if (button == 5)
		ctx->params->zoom /= 1.2;
	calculate_and_render_fractal(ctx->mlx_env, ctx->params);
	return (0);
}

int	handle_close(t_mlx_env *mlx_env)
{
	mlx_destroy_window(mlx_env->mlx, mlx_env->window);
	exit(0);
	return (0);
}
