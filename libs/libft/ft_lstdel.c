/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 07:00:21 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/10 14:48:55 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;

	while ((*alst) != NULL)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = NULL;
	}
}
