/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 17:53:29 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/14 17:58:30 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

static int		check_error(int ac, char **av, t_fdf *fdf)
{
	int error;

	if (ac != 2)
	{
		ft_putstr_fd("usage : ./Fdf <map_filename>\n", 2);
		return (1);
	}
	fdf_init(fdf);
	if ((error = file_to_map(av[1], fdf)) != 1)
	{
		if (error == -1)
			perror(av[1]);
		return (1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_fdf	fdf;
	t_ctrl	ctrl;
	t_mmlx	mlx;

	if (check_error(ac, av, &fdf))
		return (2);
	fdf.screen_w = 640;
	fdf.screen_h = 480;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, fdf.screen_w, fdf.screen_h, av[1]);
	mmlx_init(&ctrl);
	fdf_cam_center(&fdf);
	fdf_hook(&fdf, &ctrl, mlx);
	mlx_loop(mlx.mlx);
	return (1);
}
