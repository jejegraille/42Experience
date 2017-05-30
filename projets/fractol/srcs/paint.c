/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:06:23 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:18:19 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <libft.h>
#include <fractole.h>
#include <unistd.h>
#include <errno.h>

static int		get_pixel(t_point pixel, t_mx *mx, t_graph *gr, int id)
{
	int color;

	if (gr->debug)
		color = mx_rgba(100 + 155 * (id % 2), 255 - id * 10, id * 30, 255);
	else
		color = gr->fct(pixel, gr, mx);
	return (color);
}

void			paint(t_thread thread, t_image *image, t_graph *gr, int id)
{
	t_point	pixel;
	int		data_len;
	int		*data;
	t_mx	*mx;

	mx = get_mx(NULL);
	pixel.y = image->y;
	data = image->data;
	while (pixel.y < image->y + image->height)
	{
		pixel.x = image->x;
		while (pixel.x < image->x + image->width)
		{
			*data = get_pixel(pixel, mx, gr, id);
			data++;
			pixel.x += 1;
		}
		pixel.y += 1;
	}
	data_len = image->data_len * image->s_p;
	waitpid(thread.pid, NULL, 0);
	write(thread.fd, (char *)(image->data), data_len);
}
