/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:56:56 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:52:38 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <libft.h>
#include <stdlib.h>
#include <math.h>

static void		clean_render(t_image *image)
{
	int len;
	int	i;

	len = image->width * image->height;
	i = -1;
	while (++i < len)
		image->render[i] = image->data[i];
}

static void		print_image(t_image *source, t_image *image)
{
	t_point	curs;
	double	rot;
	double	x;
	double	y;
	int		i;

	curs = get_point(0, 0, 0);
	i = -1;
	while (++i < image->data_len)
	{
		rot = image->rot;
		x = (i % image->width) - image->pivot.x;
		y = (i / image->width) - image->pivot.y;
		curs.x = image->x + cos(rot) * x - sin(rot) * y;
		curs.y = image->y + sin(rot) * x + cos(rot) * y;
		mx_render_point(*source, curs, (image->render)[i]);
	}
}

void			mx_image(t_image *source, t_image *image)
{
	t_child	*next;

	if (image != NULL)
	{
		clean_render(image);
		next = image->child;
		while (next != NULL)
		{
			mx_image(image, next->image);
			next = next->next;
		}
		if (source != image)
			print_image(source, image);
	}
}
