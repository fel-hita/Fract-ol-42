/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:55:22 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/18 11:15:47 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define N 36

typedef enum	e_type
{
	MANDEL, JULIA, BURNINGSHIP
}				t_type;

typedef struct	s_point
{
	double		r;
	double		i;
}				t_point;

typedef struct	s_ptr
{
	void		*mlx_id;
	void		*mlx_win;
}				t_ptr;

typedef struct	s_img
{
	void		*mlx_img;
	int			bpp;
	int			endian;
	int			size;
	int			*data;
}				t_img;

typedef struct	s_fractal
{
	t_type		type;
	t_point		pmin;
	t_point		pmax;
	t_point		c;
	int			i;
}				t_fractal;

typedef struct	s_env
{
	t_ptr		ptr;
	t_img		img;
	t_fractal	f;
	int			move;
	int			iterations;
	int			n;
	int			start;
}				t_env;

typedef struct	s_arg
{
	int			k;
	t_env		env;
}				t_arg;
#endif
