/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_canvas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:10:48 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 17:52:17 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		pspc_b(t_point *a, t_fdf fdf)
{
	double	angle;
	t_point	c;
	t_point	center;

	mt_point(fdf.screen_w / 2, fdf.screen_h / 2, 0, &center);
	c.x = a->x * fdf.ecart * fdf.cam_s;
	c.y = a->y * fdf.ecart * fdf.cam_s;
	c.z = a->z * fdf.ecart * fdf.cam_s;
	c.x += fdf.cam_x;
	c.y += fdf.cam_y;
	angle = mt_angle(c.x, c.y, center.x, center.y);
	a->x = c.x - c.z * (center.x - c.x) / 1000;
	a->y = c.y - c.z * (center.y - c.y) / 1000;
}

static void		pspc_a(t_point *a, t_fdf fdf)
{
	double	rx;
	double	ry;
	double	rz;
	t_point c;

	rx = mt_dtor(fdf.cam_rx);
	rz = mt_dtor(fdf.cam_rz);
	ry = mt_dtor(fdf.cam_ry);
	c.x = a->x * fdf.ecart * fdf.cam_s;
	c.y = a->y * fdf.ecart * fdf.cam_s;
	c.z = a->z * fdf.ecart * fdf.cam_s;
	a->x = c.z * cos(ry) * cos(rx) + c.x * sin(rz) * sin(ry);
	a->x += c.y * cos(rz) * cos(rx);
	a->y = c.z * cos(ry) * cos(rx) + c.x * cos(rz) * cos(ry);
	a->y += c.y * sin(rz) * sin(rx);
	a->x += fdf.cam_x;
	a->y += fdf.cam_y;
}

void			canvas_point(t_point *a, t_fdf fdf)
{
	if (fdf.pspc == 0)
		pspc_a(a, fdf);
	else
		pspc_b(a, fdf);
}
