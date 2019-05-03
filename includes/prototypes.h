/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:53:31 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/18 10:55:11 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PROTOTYPES_H
# define FRACTOL_PROTOTYPES_H

# include "structs.h"

int				ft_handle_fractal(char *fractal);

void			ft_burningship(t_env *env);
void			ft_julia(t_env *env);
void			ft_julia_helper(t_arg *t, int x);

void			ft_init(t_type fractal);
void			ft_draw(t_env *env);
void			*ft_julia_draw(void *env);
void			ft_putpixel(int *data, int x, int y, unsigned int color);
void			ft_mlx_clear_pixels(int *data);

double			ft_interpolate(double start, double end, double fact);
void			ft_setcoordinates(t_fractal *j, t_point *z, int r, int i);
void			ft_julia_zoom(t_fractal *j, int r, int i, double factor);

int				ft_event_key_release(int keycode, t_env *env);
int				ft_event_mouse_press(int button, int x, int y, t_env *env);
int				ft_event_mouse_move(int x, int y, t_env *env);
int				ft_event_key_press(int keycode, t_env *env);
int				ft_exit(void *param);

t_point			ft_point(double x, double y);

unsigned int	ft_get_color(unsigned int r, unsigned int g, unsigned int b);
unsigned int	ft_color2(int n, int max);
unsigned int	ft_color1(int n, int k);
#endif
