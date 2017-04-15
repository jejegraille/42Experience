/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:42:52 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 17:24:32 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	origin(t_mmlx mlx, t_fdf fdf)
{
	char	*str;
	char	*x;
	char	*y;
	int		i;
	int		i2;

	str = ft_strnew(30);
	str[0] = '(';
	x = ft_itoa((int)floor(fdf.cam_x));
	y = ft_itoa((int)floor(fdf.cam_y));
	i = 1;
	i2 = -1;
	while (x[++i2])
		str[i++] = x[i2];
	str[i++] = ';';
	i2 = -1;
	while (y[++i2])
		str[i++] = y[i2];
	str[i] = ')';
	mlx_string_put(mlx.mlx, mlx.win,
	fdf.screen_w / 2 - 60, 0, 0X00FFFFFF, str);
	ft_memdel((void **)&x);
	ft_memdel((void **)&y);
	ft_memdel((void **)&str);
}

static void	ry(t_mmlx mlx, t_fdf fdf)
{
	char *str;
	char *tmp;

	str = ft_itoa((int)floor(fdf.cam_ry));
	tmp = ft_strjoin("Rot Y : ", str);
	ft_memdel((void **)&str);
	mlx_string_put(mlx.mlx, mlx.win, 5, 15, 0X00FFAAAA, tmp);
	ft_memdel((void **)&tmp);
}

static void	rz(t_mmlx mlx, t_fdf fdf)
{
	char *str;
	char *tmp;

	str = ft_itoa((int)floor(fdf.cam_rz));
	tmp = ft_strjoin("Rot Z : ", str);
	ft_memdel((void **)&str);
	mlx_string_put(mlx.mlx, mlx.win, 5, 30, 0X00AAFFAA, tmp);
	ft_memdel((void **)&tmp);
}

static void	rx(t_mmlx mlx, t_fdf fdf)
{
	char *str;
	char *tmp;

	str = ft_itoa((int)floor(fdf.cam_rx));
	tmp = ft_strjoin("Rot X : ", str);
	ft_memdel((void **)&str);
	mlx_string_put(mlx.mlx, mlx.win, 5, 0, 0X00AAAAFF, tmp);
	ft_memdel((void **)&tmp);
}

void		fdf_info(t_mmlx mlx, t_fdf fdf)
{
	if (fdf.info)
	{
		if (fdf.pspc == 0)
		{
			rx(mlx, fdf);
			ry(mlx, fdf);
			rz(mlx, fdf);
		}
		origin(mlx, fdf);
	}
}
