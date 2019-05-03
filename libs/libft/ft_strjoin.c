/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:56:03 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/15 01:17:22 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	char	*tmp;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	sjoin = malloc(sizeof(*s1) * len);
	if (sjoin == NULL)
		return (NULL);
	tmp = sjoin;
	sjoin = ft_strcpy(sjoin, s1);
	sjoin += ft_strlen(s1);
	ft_strcpy(sjoin, s2);
	sjoin[len - 1] = '\0';
	return (tmp);
}
