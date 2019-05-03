/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 03:37:17 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/12 16:10:25 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printer_fd(long reverse, int n, int a, int fd)
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
			ft_putchar_fd('8', fd);
		else
			ft_putchar_fd(n + 48, fd);
		zeros--;
		reverse /= 10;
	}
	while (zeros > 0)
	{
		ft_putchar_fd('0', fd);
		zeros--;
	}
}

void			ft_putnbr_fd(int nb, int fd)
{
	int n;
	int reverse;
	int a;

	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
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
		ft_putchar_fd('-', fd);
		n = nb * -1;
	}
	ft_printer_fd(reverse, n, a, fd);
}
