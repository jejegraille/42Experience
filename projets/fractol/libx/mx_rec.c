/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:40:43 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 09:52:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

void		mx_rec(t_image *image, t_rec rec, int color)
{
	int		*data;
	int		x;
	int		y;

	data = image->data;
	rec.tl.x < 0 && (rec.tl.x = 0);
	rec.tl.y < 0 && (rec.tl.y = 0);
	y = rec.tl.y;
	rec.br.x > (image->width - 1) && (rec.br.x = image->width - 1);
	rec.br.y > (image->height - 1) && (rec.br.y = image->height - 1);
	data += (int)(rec.tl.x) + y * image->width;
	while (y < rec.br.y)
	{
		x = rec.tl.x;
		while (x < rec.br.x)
		{
			*data = color;
			data++;
			x++;
		}
		y++;
		data += (int)(image->width - (int)(rec.br.x - rec.tl.x));
	}
}
