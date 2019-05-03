/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:55:32 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/12 16:07:28 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		tab_len(char **tab, size_t size)
{
	size_t	len;

	len = 0;
	while (size)
	{
		len += ft_strlen(tab[size - 1]);
		size--;
	}
	return (len);
}

char				*ft_strcon(char **tab, size_t size)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = tab_len(tab, size);
	i = 0;
	str = malloc(sizeof(*str) * (len + 1));
	while (i < size)
	{
		ft_strcpy(str, tab[i]);
		str += ft_strlen(tab[i++]);
	}
	return (str - len);
}
