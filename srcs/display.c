/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 13:58:54 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/18 10:24:27 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractal	ft_fractal_init(t_type type)
{
	t_fractal	fractal;

	fractal.pmin.r = (0 - WIN_WIDTH / 2.0) * 4.0 / WIN_WIDTH;
	fractal.pmin.i = (0 - WIN_HEIGHT / 2.0) * 4.0 / WIN_WIDTH;
	fractal.pmax.r = (WIN_WIDTH - WIN_WIDTH / 2.0) * 4.0 / WIN_WIDTH;
	fractal.pmax.i = (WIN_HEIGHT - WIN_HEIGHT / 2.0) * 4.0 / WIN_WIDTH;
	fractal.i = 0;
	fractal.type = type;
	fractal.c.r = CR;
	fractal.c.i = CI;
	return (fractal);
}

void		ft_init(t_type type)
{
	t_env	env;

	ft_memset(&env, 0, sizeof(env));
	env.iterations = 100;
	env.n = 2;
	env.f = ft_fractal_init(type);
	env.start = 0;
	env.ptr.mlx_id = mlx_init();
	env.ptr.mlx_win =
		mlx_new_window(env.ptr.mlx_id, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	mlx_hook(env.ptr.mlx_win, KEYPRESS, KEYPRESSMASK, ft_event_key_press, &env);
	mlx_hook(env.ptr.mlx_win,
			KEYRELEASE, KEYRELEASEMASK, ft_event_key_release, &env);
	mlx_hook(env.ptr.mlx_win,
			MOUSEPRESS, MOUSEPRESSMASK, ft_event_mouse_press, &env);
	mlx_hook(env.ptr.mlx_win, 6, 0, ft_event_mouse_move, &env);
	mlx_hook(env.ptr.mlx_win, 17, 0, ft_exit, &env);
	env.img.mlx_img = mlx_new_image(env.ptr.mlx_id, WIN_WIDTH, WIN_HEIGHT);
	env.img.data = (int*)mlx_get_data_addr
(env.img.mlx_img, &env.img.bpp, &env.img.endian, &env.img.size);
	ft_draw(&env);
	mlx_loop(env.ptr.mlx_id);
}

void		ft_draw(t_env *env)
{
	ft_mlx_clear_pixels(env->img.data);
	ft_julia(env);
	mlx_put_image_to_window
(env->ptr.mlx_id, env->ptr.mlx_win, env->img.mlx_img, 0, 0);
}

void		ft_mlx_clear_pixels(int *data)
{
	int		i;

	i = WIN_WIDTH * WIN_HEIGHT;
	while (--i >= 0)
		data[i] = 0x000000;
}

void		ft_putpixel(int *data, int x, int y, unsigned int color)
{
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
		data[y * WIN_WIDTH + x] = color;
}
