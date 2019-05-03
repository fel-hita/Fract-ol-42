/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:29:04 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/10 16:14:16 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t s_len;
	size_t d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (size < d_len)
		return (size + s_len);
	while (*dst)
		dst++;
	size -= d_len;
	while (*src && size > 1)
	{
		size--;
		*dst++ = *src++;
	}
	if (size == 1 || *src == 0)
		*dst = 0;
	return (s_len + d_len);
}
