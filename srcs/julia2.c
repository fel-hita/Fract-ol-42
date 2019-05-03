/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 10:09:22 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/18 10:22:35 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	ft_get_color(unsigned int r, unsigned int g, unsigned int b)
{
	char	tab[4];

	tab[3] = 0;
	tab[2] = r;
	tab[1] = g;
	tab[0] = b;
	return (*(int*)(tab));
}

unsigned int	ft_color2(int n, int max)
{
	int		tab[3];
	int		nn;
	double	t;

	t = (double)n / (double)max;
	n = (int)(t * (double)N3);
	tab[2] = n / (NC * NC);
	nn = n - tab[2] * NC * NC;
	tab[0] = nn / NC;
	tab[1] = nn - tab[0] * NC;
	return (ft_get_color(tab[0], tab[1], tab[2]));
}

unsigned int	ft_color1(int n, int k)
{
	int		x;

	x = (n / (k / 6));
	if (x == 0)
		return (ft_get_color(255, (n % (k / 6)) * (255 / (k / 6)), 0));
	if (x == 1)
		return (ft_get_color(255 - (n % (k / 6)) * (255 / (k / 6)), 255, 0));
	if (x == 2)
		return (ft_get_color(0, 255, (n % (k / 6)) * (255 / (k / 6))));
	if (x == 3)
		return (ft_get_color(0, 255 - (n % (k / 6)) * (255 / (k / 6)), 0));
	if (x == 4)
		return (ft_get_color((n % (k / 6)) * (255 / (k / 6)), 0, 255));
	if (x == 5)
		return (ft_get_color(255, 0, 255 - (n % (k / 6)) * (255 / (k / 6))));
	return (ft_get_color(0, 0, 0));
}
