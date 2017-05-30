/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:42:11 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:44:28 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <string.h>
#include <libft.h>

void		mx_render(void)
{
	t_image	*canvas;
	t_mx	*mx;

	mx = get_mx(NULL);
	canvas = &(mx->canvas);
	mx_image(canvas, canvas);
	mlx_put_image_to_window(mx->id, mx->win, mx->canvas.ptr, 0, 0);
}
