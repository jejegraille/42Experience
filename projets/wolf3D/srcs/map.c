/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:45:01 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/30 13:32:31 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <wolf.h>

t_map		*init_map(int width, int height, int depth)
{
	t_map	*map;

	map = get_map(NULL);
	map->width = width;
	map->height = height;
	map->depth = depth;
	map->len = width * depth * height;
	map->data = ft_strnew(map->len);
	return (map);
}

t_map		*get_map(t_map *save)
{
	static	t_map  map;

	if (save != NULL)
		map = *save;
	return (&map);
}
