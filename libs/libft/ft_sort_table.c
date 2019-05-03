/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:42:17 by fel-hita          #+#    #+#             */
/*   Updated: 2018/10/11 19:42:34 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_table(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] < tab[j])
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
