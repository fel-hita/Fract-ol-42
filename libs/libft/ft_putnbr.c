/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 03:27:53 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/12 16:10:04 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printer(long reverse, int n, int a)
{
	int zeros;

	zeros = 0;
	while (n > 0)
	{
		zeros++;
		reverse *= 10;
		reverse += n % 10;
		n /= 10;
	}
	while (reverse > 0)
	{
		n = reverse % 10;
		if ((a == 1) && (reverse / 10 <= 0))
			ft_putchar('8');
		else
			ft_putchar(n + 48);
		zeros--;
		reverse /= 10;
	}
	while (zeros > 0)
	{
		ft_putchar('0');
		zeros--;
	}
}

void			ft_putnbr(int nb)
{
	int n;
	int reverse;
	int a;

	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nb == -2147483648)
	{
		a = 1;
		nb += 1;
	}
	else
		a = 0;
	n = nb;
	reverse = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	ft_printer(reverse, n, a);
}
