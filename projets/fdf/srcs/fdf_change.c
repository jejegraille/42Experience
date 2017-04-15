/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:29:07 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 12:24:09 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fdf_changed(t_fdf *fdf)
{
	int changed;

	changed = 0;
	changed += !(fdf->cam_x == fdf->cam_xc);
	fdf->cam_xc = fdf->cam_x;
	changed += !(fdf->cam_y == fdf->cam_yc);
	fdf->cam_yc = fdf->cam_y;
	changed += !(fdf->cam_rx == fdf->cam_rxc);
	fdf->cam_rxc = fdf->cam_rx;
	changed += !(fdf->cam_ry == fdf->cam_ryc);
	fdf->cam_ryc = fdf->cam_ry;
	changed += !(fdf->cam_rz == fdf->cam_rzc);
	fdf->cam_rzc = fdf->cam_rz;
	changed += !(fdf->cam_s == fdf->cam_sc);
	fdf->cam_sc = fdf->cam_s;
	fdf->changed = (changed > 0);
}
