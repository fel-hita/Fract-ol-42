/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 03:02:01 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/12 17:21:07 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		no_digits(int num)
{
	int	d_count;

	d_count = 0;
	while (num > 0)
	{
		d_count++;
		num /= 10;
	}
	return (d_count);
}

static char		*special_c(int num)
{
	char	*str;

	if (num == -2147483648)
	{
		str = malloc(sizeof("-2147483648"));
		ft_strcpy(str, "-2147483648");
	}
	else
	{
		str = malloc(sizeof("0"));
		ft_strcpy(str, "0");
	}
	return (str);
}

char			*ft_itoa(int num)
{
	char	*str;
	int		d_count;

	if (num == -2147483648 || num == 0)
		return (special_c(num));
	d_count = 0;
	if (num < 0)
	{
		num *= -1;
		d_count++;
	}
	d_count += no_digits(num);
	if (NULL == (str = malloc(sizeof(char) * (d_count + 1))))
		return (NULL);
	str[d_count] = '\0';
	while (num > 0)
	{
		str[d_count - 1] = num % 10 + '0';
		num = num / 10;
		d_count--;
	}
	if (d_count == 1)
		str[0] = '-';
	return (str);
}
