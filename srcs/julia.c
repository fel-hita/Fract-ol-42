/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 10:09:27 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/18 10:22:27 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double		ft_pow(double base, int n)
{
	double		res;

	res = 1.0;
	if (n == 0)
		return (1);
	if (n == 1)
		return (base);
	if (n < 0)
	{
		n = -n;
		base = 1.0 / base;
	}
	while (n)
	{
		if (n & 1)
			res *= base;
		n >>= 1;
		base *= base;
	}
	return (res);
}

t_point		ft_compute(t_point z, t_point c, int n, t_type type)
{
	t_point		tmp;

	tmp.r = z.r;
	tmp.i = z.i;
	if (type == BURNINGSHIP)
	{
		z.r = fabs(tmp.r * tmp.r - tmp.i * tmp.i + c.r);
		z.i = fabs(2 * tmp.r * tmp.i + c.i);
	}
	else if (n == 2)
	{
		z.r = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		z.i = 2 * tmp.r * tmp.i + c.i;
	}
	else
	{
		z.r = ft_pow
(z.r * z.r + z.i * z.i, n >> 1) * cos(n * atan2(z.i, z.r)) + c.r;
		z.i = ft_pow
(z.i * z.i + z.r * z.r, n >> 1) * sin(n * atan2(z.i, z.r)) + c.i;
	}
	return (z);
}

void		ft_julia(t_env *env)
{
	int				k;
	t_arg			arg[NB_THREADS];
	pthread_t		t[NB_THREADS];
	pthread_attr_t	attr[NB_THREADS];

	k = -1;
	while (++k < NB_THREADS)
	{
		arg[k].k = k;
		arg[k].env = *env;
		pthread_attr_init(&attr[k]);
		pthread_create(&t[k], &attr[k], &ft_julia_draw, &arg[k]);
	}
	k = -1;
	while (++k < NB_THREADS)
		pthread_join(t[k], NULL);
}

void		*ft_julia_draw(void *ptr)
{
	int			x;
	t_arg		*t;

	t = (t_arg *)ptr;
	t->env.start = (t->k * WIN_WIDTH / NB_THREADS);
	x = (t->k + 1) * WIN_WIDTH / NB_THREADS + 1;
	while (--x >= t->env.start)
	{
		ft_julia_helper(t, x);
	}
	pthread_exit(NULL);
}

void		ft_julia_helper(t_arg *t, int x)
{
	unsigned int	color;
	int				y;
	t_point			z;

	y = WIN_HEIGHT + 1;
	while (--y >= 0)
	{
		ft_setcoordinates(&t->env.f, &z, x, y);
		if (t->env.f.type != JULIA)
			t->env.f.c = ft_point(z.r, z.i);
		t->env.f.i = -1;
		while (++(t->env.f.i) < t->env.iterations)
		{
			z = ft_compute(z, t->env.f.c, t->env.n, t->env.f.type);
			if ((z.r * z.r + z.i * z.i) > 4)
				break ;
		}
		if (t->env.f.i == t->env.iterations)
			color = 0x000000;
		else
			color = ft_color2(t->env.f.i, t->env.iterations);
		ft_putpixel(t->env.img.data, x, y, color);
	}
}
