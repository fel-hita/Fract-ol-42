/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:41:41 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/09 15:03:40 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*p_dst;
	size_t	i;

	p_dst = dst;
	i = 0;
	while (*(unsigned char*)src && len > 0 && i < len)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		dst++;
		src++;
		i++;
	}
	if (i < len && *(unsigned char*)src != '\0')
		if (*(unsigned char*)dst == '\0')
			return (dst);
	while (i < len)
	{
		*(unsigned char*)dst = '\0';
		i++;
		dst++;
	}
	return (p_dst);
}
