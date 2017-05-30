/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:57:13 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/16 15:53:07 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <libft.h>

void		mx_point(t_image image, t_point p, int color)
{
	int		start;
	int		x;
	int		y;

	x = (int)p.x;
	y = (int)p.y;
	if (x >= 0 && x < image.width && y >= 0 && y < image.height)
	{
		start = (x + image.width * y);
		(image.data)[start] = color;
	}
}
