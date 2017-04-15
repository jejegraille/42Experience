/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:56:02 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/11 18:11:44 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fdf_hook(t_fdf *fdf, t_ctrl *ctrl, t_mmlx mlx)
{
	t_udt *udt;

	udt = (t_udt *)ft_memalloc(sizeof(t_udt));
	udt->fdf = fdf;
	udt->ctrl = ctrl;
	udt->mlx = mlx;
	mlx_key_hook(mlx.win, &fdf_on_key, (void *)ctrl);
	mlx_mouse_hook(mlx.win, &fdf_on_mouse, (void *)ctrl);
	mlx_loop_hook(mlx.mlx, &fdf_update, (void *)udt);
}
