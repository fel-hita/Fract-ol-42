/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:04:44 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/09 15:26:09 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;
	int				i;

	i = size;
	p = (void*)malloc(sizeof(*p) * size);
	if (p == NULL)
		return (NULL);
	else
	{
		while (i > 0)
		{
			p[i - 1] = 0;
			i--;
		}
	}
	return ((void*)p);
}
