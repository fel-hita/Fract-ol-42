/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:19:47 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/18 10:22:57 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_point		ft_point(double x, double y)
{
	t_point z;

	z.r = x;
	z.i = y;
	return (z);
}

int			ft_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

double		ft_interpolate(double start, double end, double fact)
{
	return (start + ((end - start) * fact));
}

void		ft_setcoordinates(t_fractal *j, t_point *z, int r, int i)
{
	z->r = j->pmin.r + ((j->pmax.r - j->pmin.r) / WIN_WIDTH) * (double)r;
	z->i = j->pmin.i + ((j->pmax.i - j->pmin.i) / WIN_HEIGHT) * (double)i;
}

void		ft_julia_zoom(t_fractal *j, int r, int i, double factor)
{
	t_point	p;
	double	interpolation;

	p.r = (double)r * (j->pmax.r - j->pmin.r) / WIN_WIDTH + j->pmin.r;
	p.i = (double)i * (j->pmax.i - j->pmin.i) / WIN_HEIGHT + j->pmin.i;
	interpolation = 1.0 / factor;
	j->pmin.r = ft_interpolate(p.r, j->pmin.r, interpolation);
	j->pmin.i = ft_interpolate(p.i, j->pmin.i, interpolation);
	j->pmax.r = ft_interpolate(p.r, j->pmax.r, interpolation);
	j->pmax.i = ft_interpolate(p.i, j->pmax.i, interpolation);
}
