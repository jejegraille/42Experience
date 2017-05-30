/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:10:54 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:46:35 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <math.h>

static void			ver(t_image image, t_line l, int color)
{
	double ay;
	double by;

	ay = l.pa.y;
	by = l.pb.y;
	if (ay > by)
	{
		while (ay > by)
		{
			mx_point(image, get_point(-((l.b * ay + l.c) / l.a), ay, 0), color);
			ay -= 1;
		}
	}
	else
	{
		while ((int)ay < (int)by)
		{
			mx_point(image, get_point(-((l.b * ay + l.c) / l.a), ay, 0), color);
			ay++;
		}
	}
}

static void			hor(t_image image, t_line l, int color)
{
	double xa;
	double xb;

	xa = l.pa.x;
	xb = l.pb.x;
	if (xa > xb)
	{
		while (xa > xb)
		{
			mx_point(image, get_point(xa, -((l.a * xa + l.c) / l.b), 0), color);
			xa -= 1;
		}
	}
	else
		while (xa < xb)
		{
			mx_point(image, get_point(xa, -((l.a * xa + l.c) / l.b), 0), color);
			xa += 1;
		}
}

void				mx_line(t_image image, t_line line, int color)
{
	if (fabs(line.pa.x - line.pb.x) < 1 && fabs(line.pa.y - line.pb.y) < 1)
		mx_point(image, line.pa, color);
	else
	{
		if (fabs(line.pa.x - line.pb.x) > fabs(line.pa.y - line.pb.y))
			hor(image, line, color);
		else
			ver(image, line, color);
	}
}
