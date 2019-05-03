/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:29:27 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/09 19:46:08 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (NULL == (new = malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	while (start > 0)
	{
		s++;
		start--;
	}
	while (*s && len)
	{
		new[i] = (char)*s;
		len--;
		i++;
		s++;
	}
	new[i] = '\0';
	return (new);
}
