/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/16 16:40:18 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize(t_fractal *f)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, SIZE, SIZE, "Fractal Viewer");
	f->image = mlx_new_image(f->mlx, SIZE, SIZE);
	f->data_addr = mlx_get_data_addr(f->image, &f->bpp, &f->line_size,
			&f->endian);
	f->zoom = 200;
	f->offset_x = -2.0;
	f->offset_y = -1.5;
	f->max_iter = MAX_ITER;
}

void	set_fractal_params(t_fractal *f, int argc, char **argv)
{
	f->type = argv[1];
	if (argc > 2)
		f->c_re = ft_atof(argv[2]);
	else
		f->c_re = -0.7;
	if (argc > 3)
		f->c_im = ft_atof(argv[3]);
	else
		f->c_im = 0.27015;
}

void	set_hooks(t_fractal *f)
{
	mlx_key_hook(f->window, key_hook, f);
	mlx_mouse_hook(f->window, mouse_hook, f);
	mlx_hook(f->window, 17, 0L, close_hook, f);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1],
				"julia")))
	{
		printf("Usage: %s [mandelbrot | julia]\n", argv[0]);
		return (1);
	}
	initialize(&f);
	set_fractal_params(&f, argc, argv);
	draw_fractal(&f);
	mlx_put_image_to_window(f.mlx, f.window, f.image, 0, 0);
	set_hooks(&f);
	mlx_loop(f.mlx);
	return (0);
}
