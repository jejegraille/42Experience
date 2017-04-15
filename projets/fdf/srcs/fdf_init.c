/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:21:34 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 18:41:56 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fdf_init(t_fdf *fdf)
{
	fdf->changed = 0;
	fdf->width = 0;
	fdf->height = 0;
	fdf->max_z = -100000;
	fdf->min_z = 10000;
	fdf->ecart = 10;
	fdf->cam_x = 0;
	fdf->cam_y = 0;
	fdf->cam_rx = 60;
	fdf->cam_ry = 105;
	fdf->cam_rz = 100;
	fdf->cam_s = 1;
	fdf->cam_xc = 0;
	fdf->cam_yc = 0;
	fdf->cam_rxc = 0;
	fdf->cam_ryc = 0;
	fdf->cam_rzc = 0;
	fdf->cam_sc = 0;
	fdf->color = 0;
	fdf->axe = 0;
	fdf->pspc = 0;
	fdf->info = 0;
	fdf->help = 0;
}

void	fdf_reset(t_fdf *fdf)
{
	fdf->changed = 0;
	fdf->ecart = 10;
	fdf->cam_x = 0;
	fdf->cam_y = 0;
	fdf->cam_rx = 60;
	fdf->cam_ry = 105;
	fdf->cam_rz = 100;
	fdf->cam_s = 1;
	fdf_cam_center(fdf);
}
