/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:22:39 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/15 01:27:33 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int cmp;

	if (n == 0)
		return (0);
	cmp = 1;
	while ((*s1 == *s2) && *s1 && *s2 && cmp < n)
	{
		s1++;
		s2++;
		cmp++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
