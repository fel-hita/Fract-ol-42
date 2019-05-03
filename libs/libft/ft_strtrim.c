/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:08:20 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/13 06:44:53 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		l;

	if (s == NULL)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	if (*s == '\0')
	{
		dst = malloc(sizeof(char));
		*dst = '\0';
		return (dst);
	}
	l = ft_strlen(s);
	while (l && (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n'))
		l--;
	if (NULL == (dst = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	dst[l] = '\0';
	while (l)
	{
		dst[l - 1] = s[l - 1];
		l--;
	}
	return (dst);
}
