/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:57:25 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/18 10:23:06 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_handle_fractal(char *fractal)
{
	int	i;

	if (!fractal)
		return (0);
	i = -1;
	if (ft_strcmp("mandelbrot", fractal) == 0)
		ft_init(MANDEL);
	else if (ft_strcmp("julia", fractal) == 0)
		ft_init(JULIA);
	else if (ft_strcmp("burningship", fractal) == 0)
		ft_init(BURNINGSHIP);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc != 2 || !ft_handle_fractal(argv[1]))
		write(STDIN_FILENO, FRACTOL_USAGE, sizeof(FRACTOL_USAGE));
	return (0);
}
