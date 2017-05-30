/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_render_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:42:27 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:44:00 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

void		mx_render_point(t_image image, t_point p, int color)
{
	int		start;
	int		x;
	int		y;
	int		width;
	int		height;

	if (color)
	{
		x = (int)p.x;
		y = (int)p.y;
		width = (int)image.width;
		height = (int)image.height;
		if (x >= 0 && x < width && y >= 0 && y < height)
		{
			start = (x + width * y);
			(image.render)[start] = color;
		}
	}
}
