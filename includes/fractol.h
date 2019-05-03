/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:51:43 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/18 11:17:30 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include "structs.h"
# include "prototypes.h"
# include "../libs/libft/libft.h"

# define FRACTALS_COUNT 3
# define FRACTOL_USAGE "usage: fractol [julia, mandelbrot, burningship]\n"

# define WIN_WIDTH 640
# define WIN_HEIGHT 640
# define WIN_TITLE "Fractol"
# define NC 256
# define N3 NC*NC*NC
# define KEYPRESS 2
# define KEYRELEASE 3
# define MOUSEPRESS 4
# define MOTIONNOTIFY 6
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define MOUSEPRESSMASK (1L<<2)
# define POINTERMOTIONMASK (1L<<6)

# define CR    -0.7
# define CI    0.27015

# define KEY_D 		2
# define KEY_C 		8
# define KEY_Q 		12
# define KEY_W 		13
# define KEY_E 		14
# define KEY_R 		15
# define KEY_Y 		16
# define KEY_T 		17
# define KEY_I 		34
# define KEY_PLUS 	69
# define KEY_MINUS 	78
# define KEY_LEFT 	123
# define KEY_RIGHT 	124
# define KEY_DOWN 	125
# define KEY_UP 	126
# define KEY_ESC 	53

# define M_LEFT		1
# define M_RIGHT	2
# define M_MIDDLE	3
# define M_UP		4
# define M_DOWN		5

# define ABS(x) ((x) > (0.0) ? (x) : (-x))
# define NB_THREADS 4
#endif
