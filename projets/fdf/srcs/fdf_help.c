/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:10:16 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 17:55:14 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		box1(t_mmlx mlx, t_hp hp, t_fdf fdf, int size)
{
	t_point	p[4];
	t_line	l[4];
	t_tri	tri[2];

	mt_point(hp.x, fdf.screen_h - size - 5, 0, p);
	mt_point(hp.x, fdf.screen_h - 5, 0, p + 1);
	mt_point(hp.x + size, fdf.screen_h - 5, 0, p + 2);
	mt_point(hp.x + size, fdf.screen_h - size - 5, 0, p + 3);
	mt_line(p[0], p[1], l);
	mt_line(p[1], p[2], l + 1);
	mt_line(p[2], p[3], l + 2);
	mt_line(p[3], p[0], l + 3);
	mmlx_line(mlx, l[0], 0X00FFFFFF);
	mmlx_line(mlx, l[1], 0X00FFFFFF);
	mmlx_line(mlx, l[2], 0X00FFFFFF);
	mmlx_line(mlx, l[3], 0X00FFFFFF);
	if (hp.fill)
	{
		mt_tri(p[0], p[1], p[2], tri);
		mt_tri(p[0], p[3], p[2], tri + 1);
		mmlx_tri(mlx, tri[0], 0XBBFFFFFF);
		mmlx_tri(mlx, tri[1], 0XBBFFFFFF);
	}
	mlx_string_put(mlx.mlx, mlx.win, hp.x + size / 2 - 5,
	fdf.screen_h - (size) / 2 - 5 - 10, 0X00FFFFFF, hp.key);
}

static void		arrow(t_mmlx mlx, t_point o)
{
	t_tri	tri;
	t_point p[3];

	mt_point(o.x + 10, o.y + 7, 0, p);
	mt_point(o.x + 5, o.y + 12, 0, p + 1);
	mt_point(o.x + 15, o.y + 12, 0, p + 2);
	mt_tri(p[0], p[1], p[2], &tri);
	mmlx_tri(mlx, tri, 0X00FFFFFF);
	mt_point(o.x + 35, o.y + 15, 0, p);
	mt_point(o.x + 30, o.y + 10, 0, p + 1);
	mt_point(o.x + 40, o.y + 10, 0, p + 2);
	mt_tri(p[0], p[1], p[2], &tri);
	mmlx_tri(mlx, tri, 0X00FFFFFF);
	mt_point(o.x + 63, o.y + 6, 0, p);
	mt_point(o.x + 57, o.y + 11, 0, p + 1);
	mt_point(o.x + 63, o.y + 16, 0, p + 2);
	mt_tri(p[0], p[1], p[2], &tri);
	mmlx_tri(mlx, tri, 0X00FFFFFF);
	mt_point(o.x + 82, o.y + 6, 0, p);
	mt_point(o.x + 87, o.y + 11, 0, p + 1);
	mt_point(o.x + 82, o.y + 16, 0, p + 2);
	mt_tri(p[0], p[1], p[2], &tri);
	mmlx_tri(mlx, tri, 0X00FFFFFF);
}

static void		direction(t_mmlx mlx, t_fdf fdf)
{
	int		m;
	int		size;
	t_hp	hp[4];
	t_point o;

	m = 5;
	size = 20;
	fdf_hp(" ", 170 + (m + size) * 0, 0, hp);
	fdf_hp(" ", 170 + (m + size) * 1, 0, hp + 1);
	fdf_hp(" ", 170 + (m + size) * 2, 0, hp + 2);
	fdf_hp(" ", 170 + (m + size) * 3, 0, hp + 3);
	box1(mlx, hp[0], fdf, size);
	box1(mlx, hp[1], fdf, size);
	box1(mlx, hp[2], fdf, size);
	box1(mlx, hp[3], fdf, size);
	mlx_string_put(mlx.mlx, mlx.win, hp[0].x - 1,
	fdf.screen_h - size - m - 20, 0X00FFFFFF, " Move cam");
	mt_point(hp[0].x, fdf.screen_h - size - 5, 0, &o);
	arrow(mlx, o);
}

static int		rotation(t_mmlx mlx, t_fdf fdf)
{
	int		m;
	int		size;
	t_hp	hp[6];

	m = 5;
	size = 20;
	fdf_hp("Q", 5 + (m + size) * 0, 0, hp);
	fdf_hp("W", 5 + (m + size) * 1, 0, hp + 1);
	fdf_hp("A", 5 + (m + size) * 2, 0, hp + 2);
	fdf_hp("S", 5 + (m + size) * 3, 0, hp + 3);
	fdf_hp("Z", 5 + (m + size) * 4, 0, hp + 4);
	fdf_hp("X", 5 + (m + size) * 5, 0, hp + 5);
	box1(mlx, hp[0], fdf, size);
	box1(mlx, hp[1], fdf, size);
	mlx_string_put(mlx.mlx, mlx.win, hp[0].x,
	fdf.screen_h - size - m - 20, 0X00BBBBFF, "RotX");
	box1(mlx, hp[2], fdf, size);
	box1(mlx, hp[3], fdf, size);
	mlx_string_put(mlx.mlx, mlx.win, hp[2].x,
	fdf.screen_h - size - m - 20, 0X00FFBBBB, "RotY");
	box1(mlx, hp[4], fdf, size);
	box1(mlx, hp[5], fdf, size);
	mlx_string_put(mlx.mlx, mlx.win, hp[4].x,
	fdf.screen_h - size - m - 20, 0X00BBFFBB, "RotZ");
	return (1);
}

void			fdf_help(t_mmlx mlx, t_fdf fdf)
{
	int		m;
	int		size;
	t_hp	hp[6];

	m = 10;
	size = 35;
	fdf_hp("P", fdf.screen_w - (m + size) * 1, fdf.color, hp);
	fdf_hp("O", fdf.screen_w - (m + size) * 2, fdf.axe, hp + 1);
	fdf_hp("I", fdf.screen_w - (m + size) * 3, fdf.info, hp + 2);
	fdf_hp("U", fdf.screen_w - (m + size) * 4, fdf.pspc, hp + 3);
	fdf_hp("H", fdf.screen_w - (m + size) * 5, fdf.help, hp + 4);
	box1(mlx, hp[0], fdf, size);
	box1(mlx, hp[1], fdf, size);
	box1(mlx, hp[2], fdf, size);
	box1(mlx, hp[3], fdf, size);
	box1(mlx, hp[4], fdf, size);
	if (fdf.help)
	{
		(fdf.pspc == 0) && rotation(mlx, fdf);
		direction(mlx, fdf);
		fdf_hp("R", 290, 0, hp + 4);
		box1(mlx, hp[4], fdf, 20);
		mlx_string_put(mlx.mlx, mlx.win, hp[4].x - 10,
		fdf.screen_h - 45, 0X00FFFFFF, "Reset");
	}
}
