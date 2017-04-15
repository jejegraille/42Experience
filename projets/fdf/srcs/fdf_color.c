/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:30:33 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 19:58:13 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			fdf_color(t_fdf fdf, double z)
{
	double	color;
	double	r;

	(void)fdf;
	r = z * 0.2;
	if (z <= 0)
		color = mt_rgba(100, 130, fmax(100, 255 + 255 * r), 150);
	if (z > 0 && z < 10)
		color = mt_rgba(30 + fmin(70, 70 * r),
		fmax(200, 55 - 55 * r), 50, 150);
	if (z >= 10)
		color = mt_rgba(70 + fmin(155, 100 * r),
		fmax(200, 55 - 55 * r), 30 + fmin(100, 70 * r), 150);
	return (color);
}
