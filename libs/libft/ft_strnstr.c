/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:15:07 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/09 15:03:20 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (to_find[j] == str[i + j] && j + i < len)
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char*)str + i);
			}
			j++;
		}
		i++;
	}
	if (*to_find == '\0')
		return ((char*)(str));
	return (0);
}
