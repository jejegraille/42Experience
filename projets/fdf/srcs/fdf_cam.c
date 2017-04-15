/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:32:44 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 17:49:05 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void				fdf_cam_center(t_fdf *fdf)
{
	int		max;
	int		max2;

	max = fdf->screen_w / fdf->width;
	max2 = fdf->screen_h / fdf->height;
	fdf->ecart = max > max2 ? max2 : max;
	fdf->cam_s = 0.8;
	fdf->cam_x = (fdf->screen_w - fdf->width * fdf->ecart * fdf->cam_s) / 2;
	fdf->cam_y = (fdf->screen_h - fdf->height * fdf->ecart * fdf->cam_s) / 2;
}

static void			part_2(t_fdf *fdf, t_ctrl *ctrl)
{
	if (ctrl->last_key == 12)
		fdf->cam_rx = mt_link(0, fdf->cam_rx - 0.5, 360);
	if (ctrl->last_key == 13)
		fdf->cam_rx = mt_link(0, fdf->cam_rx + 0.5, 360);
	if (ctrl->last_key == 0)
		fdf->cam_ry = mt_link(0, fdf->cam_ry - 0.5, 360);
	if (ctrl->last_key == 1)
		fdf->cam_ry = mt_link(0, fdf->cam_ry + 0.5, 360);
	if (ctrl->last_key == 6)
		fdf->cam_rz = mt_link(0, fdf->cam_rz - 0.5, 360);
	if (ctrl->last_key == 7)
		fdf->cam_rz = mt_link(0, fdf->cam_rz + 0.5, 360);
}

static void			part_unic(t_fdf *fdf, t_ctrl *ctrl)
{
	int k;

	k = ctrl->last_key;
	if (k == 35 || k == 34 || k == 31 || k == 4 || k == 15 || k == 32)
	{
		k == 35 && (fdf->color = fdf->color ? 0 : 1);
		k == 34 && (fdf->info = fdf->info ? 0 : 1);
		k == 31 && (fdf->axe = fdf->axe ? 0 : 1);
		k == 4 && (fdf->help = fdf->help ? 0 : 1);
		k == 32 && (fdf->pspc = fdf->pspc ? 0 : 1);
		if (k == 15)
			fdf_reset(fdf);
		ctrl->last_key = -1;
	}
}

void				fdf_cam_update(t_fdf *fdf, t_ctrl *ctrl)
{
	double moove;

	if (ctrl->mouse_btn == 5 || ctrl->mouse_btn == 4)
		fdf->cam_s *= ctrl->mouse_btn == 5 ? 1.05 : 0.95;
	part_unic(fdf, ctrl);
	if (ctrl->last_key != -1)
	{
		moove = 3;
		if (ctrl->last_key == 123)
			fdf->cam_x += -1 * moove;
		if (ctrl->last_key == 124)
			fdf->cam_x += 1 * moove;
		if (ctrl->last_key == 125)
			fdf->cam_y += 1 * moove;
		if (ctrl->last_key == 126)
			fdf->cam_y += -1 * moove;
		part_2(fdf, ctrl);
	}
}
