/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/05/31 22:08:55 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 800
# define MAX_ITER 42
# define ESC_KEY 53

typedef struct s_complex
{
	double				re;
	double				im;
}						t_complex;

typedef struct s_complex_values
{
	t_complex			z;
	t_complex			c;
}						t_complex_values;

typedef struct s_mlx_env
{
	void				*mlx;
	void				*window;
	void				*image;
	char				*data_addr;
	int					bpp;
	int					line_size;
	int					endian;
}						t_mlx_env;

typedef struct s_fractal_params
{
	char				*type;
	double				zoom;
	double				offset_x;
	double				offset_y;
	int					max_iter;
	t_complex			julia_c;
}						t_fractal_params;

typedef struct s_context
{
	t_mlx_env			*mlx_env;
	t_fractal_params	*params;
}						t_context;

t_complex				init_complex(double re, double im);
void					put_color_to_pixel(t_mlx_env *env, int x, int y,
							int color);
int						iterate_fractal(t_complex z, t_complex c, int max_iter);
void					calculate_and_render_fractal(t_mlx_env *mlx_env,
							t_fractal_params *params);
t_mlx_env				*initialize_mlx(void);
void					set_fractal_params(t_fractal_params *params, int argc,
							char **argv);
int						handle_keypress(int keycode, t_mlx_env *mlx_env);
int						handle_mouse(int button, int x, int y, t_context *ctx);
int						handle_close(t_mlx_env *mlx_env);
void					render_pixel(t_mlx_env *mlx_env,
							t_fractal_params *params, int x, int y);
t_complex_values		calculate_initial_values(t_fractal_params *params,
							int x, int y);
int						determine_color(int iteration, int max_iter);

double					ft_atof(const char *str);
int						ft_strcmp(const char *s1, const char *s2);

#endif