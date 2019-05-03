/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:05:21 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/18 10:22:20 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_fractal_move(t_fractal *f, int keycode)
{
	if (keycode == KEY_RIGHT)
	{
		f->pmin.r -= 0.05;
		f->pmax.r -= 0.05;
	}
	else if (keycode == KEY_LEFT)
	{
		f->pmin.r += 0.05;
		f->pmax.r += 0.05;
	}
	else if (keycode == KEY_UP)
	{
		f->pmin.i += 0.05;
		f->pmax.i += 0.05;
	}
	else if (keycode == KEY_DOWN)
	{
		f->pmin.i -= 0.05;
		f->pmax.i -= 0.05;
	}
}

int		ft_event_key_release(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		ft_mlx_clear_pixels(env->img.data);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		ft_event_key_press(int keycode, t_env *env)
{
	if (keycode == KEY_PLUS)
		env->iterations += 10;
	else if (keycode == KEY_MINUS)
		env->iterations -= 10;
	else if (keycode == KEY_R)
		env->n++;
	else if (keycode == KEY_Y)
		env->n--;
	else if (keycode == KEY_T)
		env->f.type = (++env->f.type) % 3;
	else
		ft_fractal_move(&env->f, keycode);
	if (env->f.type == JULIA && !env->move)
	{
		env->f.c.r = CR;
		env->f.c.i = CI;
	}
	ft_draw(env);
	return (1);
}

int		ft_event_mouse_press(int button, int x, int y, t_env *env)
{
	if (button == M_UP)
		ft_julia_zoom(&env->f, x, y, 1.0 / 0.9);
	else if (button == M_DOWN)
		ft_julia_zoom(&env->f, x, y, 0.9);
	else if (!env->move && button == M_RIGHT)
		env->move = 1;
	else if (env->move && button == M_LEFT)
		env->move = 0;
	ft_draw(env);
	return (1);
}

int		ft_event_mouse_move(int x, int y, t_env *env)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		;
	else if (env->move)
	{
		env->f.c.r = (0.0018 * (WIN_WIDTH / 2 - x));
		env->f.c.i = (0.0018 * (WIN_HEIGHT / 2 - y));
	}
	ft_draw(env);
	return (1);
}
