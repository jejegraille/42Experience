/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 02:28:22 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/19 06:21:08 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = 0;
	if (min >= max)
		*range = NULL;
	else
	{
		*range = malloc(sizeof(int) * (max - min + 1));
		while (min < max)
		{
			range[0][i] = min;
			i++;
			min++;
		}
	}
	return (i);
}
