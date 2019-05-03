/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:56:43 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/12 15:15:09 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	p_dst = dst;
	p_src = (void*)src;
	while (n > 0)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
		n--;
	}
	return (dst);
}
