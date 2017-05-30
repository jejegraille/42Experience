/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_rgba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:34:06 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:43:15 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

static int		self_range(int min, int value, int max)
{
	if (min > value)
		value = min;
	else if (max < value)
		value = max;
	return (value);
}

int				mx_rgba(int red, int green, int blue, int alpha)
{
	alpha = self_range(0, alpha, 255);
	red = self_range(0, red, 255);
	green = self_range(0, green, 255);
	blue = self_range(0, blue, 255);
	alpha = (255 - alpha) * 16777216;
	red = red * 65536;
	green = green * 256;
	return (alpha + red + green + blue);
}

int				rgba_toi(t_rgba co)
{
	return (mx_rgba(co.r, co.g, co.b, co.a));
}
