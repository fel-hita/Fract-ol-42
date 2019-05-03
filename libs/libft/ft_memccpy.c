/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:18:51 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/12 15:15:22 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*p_dst;
	unsigned const char	*p_src;

	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	while (n > 0)
	{
		*p_dst = (unsigned char)*p_src;
		if (*p_src == (unsigned char)c)
			return (++p_dst);
		p_dst++;
		p_src++;
		n--;
	}
	return (NULL);
}
