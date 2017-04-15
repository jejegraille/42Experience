/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:16:05 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/14 19:26:44 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			fdf_update(void *upd)
{
	t_udt	*udt;
	t_ctrl	*ctrl;
	t_fdf	*fdf;
	t_mmlx	mlx;

	udt = (t_udt *)upd;
	fdf = udt->fdf;
	ctrl = udt->ctrl;
	mlx = udt->mlx;
	fdf_cam_update(fdf, ctrl);
	mlx_clear_window(mlx.mlx, mlx.win);
	fdf_changed(fdf);
	fdf_draw(*fdf, mlx);
	fdf_info(mlx, *fdf);
	fdf_help(mlx, *fdf);
	if (ctrl->last_key == 53)
	{
		del_tab(fdf);
		ft_memdel((void **)&udt);
		mlx_destroy_window(mlx.mlx, mlx.win);
		exit(1);
	}
	fdf_ctrl_update(ctrl);
	return (0);
}
