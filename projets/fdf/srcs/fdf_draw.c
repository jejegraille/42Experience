/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:03:57 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 19:56:30 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		draw_face(t_mmlx mlx, t_fdf fdf, t_point *p)
{
	int			color;
	t_tri		tri[2];
	t_line		l[4];

	color = fdf_color(fdf, (p[0].z + p[1].z + p[2].z + p[3].z) / 4);
	canvas_point(p, fdf);
	canvas_point(p + 1, fdf);
	canvas_point(p + 2, fdf);
	canvas_point(p + 3, fdf);
	mt_line(p[0], p[1], l);
	mt_line(p[1], p[2], l + 1);
	mt_line(p[2], p[3], l + 2);
	mt_line(p[3], p[0], l + 3);
	if (fdf.color && fdf.changed == 0)
	{
		mt_tri(p[0], p[1], p[2], tri);
		mt_tri(p[0], p[3], p[2], tri + 1);
		mmlx_tri(mlx, tri[0], color);
		mmlx_tri(mlx, tri[1], color);
	}
	mmlx_line(mlx, l[0], fdf.color ? 0XAAFFFFFF : color);
	mmlx_line(mlx, l[1], fdf.color ? 0XAAFFFFFF : color);
	mmlx_line(mlx, l[2], fdf.color ? 0XAAFFFFFF : color);
	mmlx_line(mlx, l[3], fdf.color ? 0XAAFFFFFF : color);
}

static void		face(t_fdf fdf, t_mmlx mlx)
{
	int		x;
	int		y;
	t_point	p[4];

	y = 1;
	while (y < fdf.height)
	{
		x = 1;
		while (x < fdf.width)
		{
			mt_point(x - 1, y - 1, fdf.map[y - 1][x - 1], &(p[0]));
			mt_point(x - 1, y, fdf.map[y][x - 1], &(p[1]));
			mt_point(x, y, fdf.map[y][x], &(p[2]));
			mt_point(x, y - 1, fdf.map[y - 1][x], &(p[3]));
			draw_face(mlx, fdf, p);
			x++;
		}
		y++;
	}
}

static void		axes(t_fdf fdf, t_mmlx mlx)
{
	t_point	a;
	t_point	b;
	t_line	l;

	mt_point(0, 0, 0, &a);
	canvas_point(&a, fdf);
	mt_point(100, 0, 0, &b);
	canvas_point(&b, fdf);
	mt_line(a, b, &l);
	mmlx_line(mlx, l, mt_rgba(100, 100, 255, 255));
	mt_point(0, 100, 0, &b);
	canvas_point(&b, fdf);
	mt_line(a, b, &l);
	mmlx_line(mlx, l, mt_rgba(255, 100, 100, 255));
	mt_point(0, 0, 100, &b);
	canvas_point(&b, fdf);
	mt_line(a, b, &l);
	mmlx_line(mlx, l, mt_rgba(100, 255, 100, 255));
}

void			fdf_draw(t_fdf fdf, t_mmlx mlx)
{
	int ey;

	face(fdf, mlx);
	if (fdf.axe)
		axes(fdf, mlx);
	if (fdf.width < 2 || fdf.height < 2)
	{
		ey = 1;
		mlx_string_put(mlx.mlx, mlx.win, fdf.screen_w / 2 - 100,
		fdf.screen_h / 2 - 10, 0X00FF0000, "Error map can't be drawn");
		if (fdf.width < 2 && (ey += 1))
			mlx_string_put(mlx.mlx, mlx.win, fdf.screen_w / 2 - 100,
			fdf.screen_h / 2 - 10 + 25, 0X00FF0000, "width < 2");
		if (fdf.height < 2)
			mlx_string_put(mlx.mlx, mlx.win, fdf.screen_w / 2 - 100,
			fdf.screen_h / 2 - 10 + 25 * ey, 0X00FF0000, "height < 2");
	}
}
