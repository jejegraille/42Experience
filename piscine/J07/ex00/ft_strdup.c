/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 04:08:22 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/18 20:29:02 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*new_str;

	size = 0;
	while (src[size] != '\0')
	{
		size++;
	}
	new_str = malloc(sizeof(char) * size);
	i = 0;
	while (i <= size)
	{
		new_str[i] = src[i];
		i++;
	}
	return (new_str);
}
