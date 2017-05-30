/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:57:07 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:34:56 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <stdlib.h>
#include <libft.h>

void		del_image(t_image *image)
{
	ft_memdel((void **)&(image->render));
	ft_memdel((void **)&(image->data));
}

t_image		get_image(int width, int height)
{
	t_image i;
	t_mx	*mx;

	mx = get_mx(NULL);
	i.x = 0;
	i.y = 0;
	i.pivot = get_point((double)(width / 2), (double)(height / 2), 0);
	i.rot = 0;
	i.width = width;
	i.height = height;
	i.ptr = NULL;
	i.data_len = width * height;
	i.data = (int *)ft_memalloc(sizeof(int) * i.data_len);
	i.render = (int *)ft_memalloc(sizeof(int) * i.data_len);
	i.child = NULL;
	i.parent = NULL;
	i.s_p = mx->init ? mx->canvas.s_p : 4;
	return (i);
}
