/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmlx_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:40:28 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/14 17:25:51 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mmlx.h>
#include <math.h>
#include <mlx.h>

static void			ver(t_mmlx mlx, t_line l, int color)
{
	double ay;
	double by;

	ay = l.pa.y;
	by = l.pb.y;
	if (ay > by)
	{
		while (ay > by)
		{
			mlx_pixel_put(mlx.mlx, mlx.win,
			-((l.b * ay + l.c) / l.a), ay, color);
			ay -= 1;
		}
	}
	else
	{
		while ((int)ay < (int)by)
		{
			mlx_pixel_put(mlx.mlx, mlx.win,
			-((l.b * ay + l.c) / l.a), ay, color);
			ay++;
		}
	}
}

static void			hor(t_mmlx mlx, t_line l, int color)
{
	double xa;
	double xb;

	xa = l.pa.x;
	xb = l.pb.x;
	if (xa > xb)
	{
		while (xa > xb)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, xa,
			-((l.a * xa + l.c) / l.b), color);
			xa -= 1;
		}
	}
	else
		while (xa < xb)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, xa,
			-((l.a * xa + l.c) / l.b), color);
			xa += 1;
		}
}

void				mmlx_line(t_mmlx mlx, t_line line, int color)
{
	if (fabs(line.pa.x - line.pb.x) < 1 && fabs(line.pa.y - line.pb.y) < 1)
		mmlx_point(mlx, line.pa, color);
	else
	{
		if (fabs(line.pa.x - line.pb.x) > fabs(line.pa.y - line.pb.y))
			hor(mlx, line, color);
		else
			ver(mlx, line, color);
	}
}
