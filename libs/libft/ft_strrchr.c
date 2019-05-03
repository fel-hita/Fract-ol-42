/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:45:31 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/11 15:38:14 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (*s)
		s++;
	if ((char)c == (char)*s)
		return ((char *)s);
	while (len + 1 > 0)
	{
		if ((char)c == (char)*s)
			return ((char *)s);
		len--;
		s--;
	}
	return (NULL);
}
