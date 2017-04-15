/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_rgba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:14:11 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/12 17:08:59 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		mt_rgba(int red, int green, int blue, int alpha)
{
	alpha = mt_range(0, alpha, 255);
	red = mt_range(0, red, 255);
	green = mt_range(0, green, 255);
	blue = mt_range(0, blue, 255);
	alpha = (255 - alpha) * 16 * 16 * 16 * 16 * 16 * 16;
	red = red * 16 * 16 * 16 * 16;
	green = green * 16 * 16;
	return (alpha + red + green + blue);
}
