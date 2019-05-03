/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:59:13 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/08 19:22:19 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	tmp[len + 1];
	void	*p;

	p = dst;
	if (len > 65535)
		return (NULL);
	if (p == src)
		return (p);
	else if (p > src && p < src + len)
	{
		ft_memcpy(tmp, src, len);
		ft_memcpy(p, tmp, len);
	}
	else
		ft_memcpy(p, src, len);
	return (p);
}
