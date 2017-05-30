/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 21:38:09 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/21 21:51:46 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

void	paste_image(t_image *canv, t_image *im)
{
	int	*data_c;
	int	i;
	int	x;
	int	y;

	data_c = canv->data;
	i = -1;
	while (++i < im->data_len)
	{
		x = (i % im->width);
		y = (i / im->width);
		data_c[(x + im->x) + y * canv->width] = im->data[x + y * im->width];
	}
}
