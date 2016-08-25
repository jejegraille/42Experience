/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_interger_table.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 23:42:46 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/09 23:45:32 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int maxmin[2];
	int i;
	int save;
	int position;
	int count;

	count = size;
	while (count > 0)
	{
		count--;
		i = count;
		maxmin[0] = maxmin[1];
		save = tab[count];
		while (i >= 0)
		{
			position = (maxmin[0] < tab[i]) ? i : position;
			maxmin[0] = (maxmin[0] < tab[i]) ? tab[i] : maxmin[0];
			maxmin[1] = (maxmin[1] > tab[i]) ? tab[i] : maxmin[1];
			i--;
		}
		tab[count] = maxmin[0];
		tab[position] = save;
	}
}
