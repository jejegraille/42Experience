/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 09:43:10 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:34:22 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <stdlib.h>
#include <libft.h>

t_image		get_mlx_image(int width, int height)
{
	t_image i;
	t_mx	*mx;

	mx = get_mx(NULL);
	if (mx->init == 0)
		ft_putstr_fd("Error : please init mx befor use get_mlx_image()", 2);
	i.x = 0;
	i.y = 0;
	i.pivot = get_point((double)(width / 2), (double)(height / 2), 0);
	i.rot = 0;
	i.width = width;
	i.height = height;
	i.ptr = mlx_new_image(mx->id, width, height);
	i.data_len = width * height;
	i.data = (int *)mlx_get_data_addr(i.ptr, &(i.s_p), &(i.s_l), &(i.edn));
	i.render = i.data;
	i.s_p /= 8;
	i.child = NULL;
	i.parent = NULL;
	return (i);
}
