/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmlx_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:58:26 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 20:28:24 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mmlx.h>
#include <math.h>

static int			on_line(double x, t_line l)
{
	if ((x >= l.pb.x && x <= l.pa.x) || (x >= l.pa.x && x <= l.pb.x))
		return (1);
	return (0);
}

static void			find_y(t_line *l, double x, double *y)
{
	int		i;
	double	tmp;

	i = -1;
	y[0] = y[3];
	y[1] = y[2];
	while (++i < 3)
	{
		if (on_line(x, l[i]))
		{
			tmp = -(l[i].a * x + l[i].c) / l[i].b;
			y[0] = tmp < y[0] ? tmp : y[0];
			y[1] = tmp > y[1] ? tmp : y[1];
		}
	}
}

static void			draw(t_mmlx mlx, t_point a, t_point b, int color)
{
	while (a.y < b.y)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, a.x, a.y, color);
		a.y += 1;
	}
}

void				mmlx_tri(t_mmlx mlx, t_tri tri, int color)
{
	t_line	l[4];
	double	mi_x;
	double	ma_x;
	double	y[4];
	t_point	p[2];

	mt_line(tri.a, tri.b, l);
	mt_line(tri.a, tri.c, l + 1);
	mt_line(tri.b, tri.c, l + 2);
	mi_x = ceil(fmin(fmin(tri.a.x, tri.b.x), tri.c.x));
	ma_x = floor(fmax(fmax(tri.a.x, tri.b.x), tri.c.x));
	y[2] = fmin(fmin(tri.a.y, tri.b.y), tri.c.y);
	y[3] = fmax(fmax(tri.a.y, tri.b.y), tri.c.y);
	while (mi_x < ma_x)
	{
		find_y(l, mi_x, y);
		mt_point(mi_x, y[0], 0, &(p[0]));
		mt_point(mi_x, y[1], 0, &(p[1]));
		draw(mlx, p[0], p[1], color);
		mi_x = mi_x + 1;
	}
}
