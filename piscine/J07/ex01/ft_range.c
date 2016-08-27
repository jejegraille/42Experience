/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 02:15:29 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/18 20:30:50 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *table;
	int i;

	if (min >= max)
		return (NULL);
	else
	{
		table = malloc(sizeof(int) * (max - min + 1));
		i = 0;
		while (min < max)
		{
			table[i] = min;
			i++;
			min++;
		}
		return (table);
	}
}
