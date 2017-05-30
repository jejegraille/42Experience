/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:02:46 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 17:24:26 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <fractole.h>
#include <string.h>

int		fct_mandelbrot(t_point pixel, t_graph *gr, t_mx *mx)
{
	int		color;
	double	tmp;
	t_algo	alg;

	alg.limit = 4;
	alg.it_max = gr->it_max;
	alg.zi = 0;
	alg.zr = 0;
	alg.it = 0;
	alg.cr = (pixel.x - mx->width / 2) * gr->scale.x + gr->center.x;
	alg.ci = (pixel.y - mx->height / 2) * gr->scale.y + gr->center.y;
	alg.z = 0;
	while (alg.z < alg.limit && alg.it < alg.it_max)
	{
		tmp = alg.zr;
		alg.zr = alg.zr * alg.zr - alg.zi * alg.zi + alg.cr;
		alg.zi = 2 * alg.zi * tmp + alg.ci;
		alg.z = alg.zr * alg.zr + alg.zi * alg.zi;
		alg.it += 1;
	}
	alg.it = alg.it == alg.it_max ? 5 : alg.it;
	color = mx_rgba(gr->rgb.r * alg.it,
			gr->rgb.g * alg.it, gr->rgb.b * alg.it, 255);
	return (color);
}

int		fct_julia(t_point pixel, t_graph *gr, t_mx *mx)
{
	int		color;
	double	tmp;
	t_algo	alg;

	alg.limit = 4;
	alg.it_max = gr->it_max;
	alg.zi = (pixel.x - mx->width / 2) * gr->scale.x + gr->center.x;
	alg.zr = (pixel.y - mx->height / 2) * gr->scale.y + gr->center.y;
	alg.it = 0;
	alg.cr = 0.4 + 0.2 * (gr->mouse_r.x - 0.5);
	alg.ci = 0.3 + 0.5 * (gr->mouse_r.y - 0.5);
	alg.z = 0;
	while (alg.z < alg.limit && alg.it < alg.it_max)
	{
		tmp = alg.zr;
		alg.zr = alg.zr * alg.zr - alg.zi * alg.zi + alg.cr;
		alg.zi = 2 * alg.zi * tmp + alg.ci;
		alg.z = alg.zr * alg.zr + alg.zi * alg.zi;
		alg.it += 1;
	}
	alg.it = alg.it == alg.it_max ? 5 : alg.it;
	color = mx_rgba(gr->rgb.r * alg.it,
			gr->rgb.g * alg.it, gr->rgb.b * alg.it, 255);
	return (color);
}

int		fct_burning_ship(t_point pixel, t_graph *gr, t_mx *mx)
{
	int		color;
	t_algo	alg;
	double	tmp_r;
	double	tmp_i;

	alg.limit = 4;
	alg.it_max = gr->it_max;
	alg.it = 0;
	alg.cr = (pixel.x - mx->width / 2) * gr->scale.x + gr->center.x;
	alg.ci = (pixel.y - mx->height / 2) * gr->scale.y + gr->center.y;
	alg.zr = 0;
	alg.zi = 0;
	while (alg.zi * alg.zi + alg.zr * alg.zr < alg.limit && alg.it < alg.it_max)
	{
		tmp_r = alg.zr * alg.zr - alg.zi * alg.zi + alg.cr;
		tmp_i = 2 * fabs(alg.zr * alg.zi) + alg.ci;
		alg.zr = tmp_r;
		alg.zi = tmp_i;
		alg.it += 1;
	}
	alg.it = alg.it == alg.it_max ? 5 : alg.it;
	color = mx_rgba(gr->rgb.r * alg.it,
			gr->rgb.g * alg.it, gr->rgb.b * alg.it, 255);
	return (color);
}

int		fct_burning_bird(t_point pixel, t_graph *gr, t_mx *mx)
{
	int		color;
	t_algo	alg;
	double	tmp_r;
	double	tmp_i;

	alg.limit = 4;
	alg.it_max = gr->it_max;
	alg.it = 0;
	alg.cr = (pixel.x - mx->width / 2) * gr->scale.x + gr->center.x;
	alg.ci = (pixel.y - mx->height / 2) * gr->scale.y + gr->center.y;
	alg.zr = 0;
	alg.zi = 0;
	while (alg.zi * alg.zi + alg.zr * alg.zr < alg.limit && alg.it < alg.it_max)
	{
		tmp_r = alg.zr * alg.zr - alg.zi * alg.zi + alg.cr;
		tmp_i = -2 * alg.zr * fabs(alg.zi) + alg.ci;
		alg.zr = tmp_r;
		alg.zi = tmp_i;
		alg.it += 1;
	}
	alg.it = alg.it == alg.it_max ? 5 : alg.it;
	color = mx_rgba(gr->rgb.r * alg.it,
			gr->rgb.g * alg.it, gr->rgb.b * alg.it, 255);
	return (color);
}

int		fct_fusee(t_point pixel, t_graph *gr, t_mx *mx)
{
	int		color;
	double	tmp;
	t_algo	alg;

	alg.limit = 4;
	alg.it_max = gr->it_max;
	alg.zi = 0;
	alg.zr = 0;
	alg.it = 0;
	alg.cr = (pixel.x - mx->width / 2) * gr->scale.x + gr->center.x;
	alg.ci = (pixel.y - mx->height / 2) * gr->scale.y + gr->center.y;
	alg.z = 0;
	while (alg.z < alg.limit && alg.it < alg.it_max)
	{
		tmp = alg.zr;
		alg.zr = (alg.zr * alg.zr - alg.zi * alg.zi + alg.cr) * 0.32;
		alg.zi = 2 * alg.zi * tmp + alg.ci;
		alg.z = alg.zr * alg.zr + alg.zi * alg.zi;
		alg.it += 1;
	}
	alg.it = alg.it == alg.it_max ? 5 : alg.it;
	color = mx_rgba(gr->rgb.r * alg.it,
			gr->rgb.g * alg.it, gr->rgb.b * alg.it, 255);
	return (color);
}
