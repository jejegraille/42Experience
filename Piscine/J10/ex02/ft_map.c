/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 11:07:29 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/20 11:53:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *new_tab;

	new_tab = malloc(sizeof(int) * length);
	i = -1;
	while (++i < length)
		new_tab[i] = f(tab[i]);
	return (new_tab);
}
