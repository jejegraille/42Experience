/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 07:19:17 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/12 10:23:48 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_compact(char **tab, int length)
{
	char	*table2[length];
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (i < length)
	{
		if (tab[i] != 0)
		{
			table2[i2] = tab[i];
			i2++;
		}
		i++;
	}
	length = i2;
	i2 = 0;
	while (i2 < length)
	{
		tab[i2] = table2[i2];
		i2++;
	}
	tab[i2] = 0;
	return (length - i);
}
