/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:54:18 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 18:40:52 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mmlx.h>
# include <math.h>

typedef struct	s_fdf
{
	int		**map;
	int		width;
	int		height;
	int		min_z;
	int		max_z;
	int		ecart;
	int		screen_w;
	int		screen_h;
	int		color;
	int		info;
	int		axe;
	int		changed;
	int		help;
	int		pspc;
	double	cam_x;
	double	cam_y;
	double	cam_rx;
	double	cam_ry;
	double	cam_rz;
	double	cam_s;
	double	cam_xc;
	double	cam_yc;
	double	cam_rxc;
	double	cam_ryc;
	double	cam_rzc;
	double	cam_sc;

}				t_fdf;

typedef struct	s_hp
{
	int		fill;
	int		x;
	char	*key;
}				t_hp;

typedef struct	s_udt
{
	t_fdf	*fdf;
	t_ctrl	*ctrl;
	t_mmlx	mlx;
}				t_udt;

void			fdf_ctrl_update(t_ctrl *ctrl);
void			del_tab(t_fdf *fdf);
void			fdf_init(t_fdf *fdf);
void			fdf_reset(t_fdf *fdf);
void			fdf_cam_update(t_fdf *fdf, t_ctrl *ctrl);
int				file_to_map(char *file, t_fdf *fdf);
void			fdf_draw(t_fdf fdf, t_mmlx mlx);
void			fdf_hook(t_fdf *fdf, t_ctrl *ctrl, t_mmlx mlx);
int				fdf_on_key(int keycode, void *control);
int				fdf_on_mouse(int button, int x, int y, void *control);
int				fdf_update(void *upt);
void			fdf_cam_center(t_fdf *fdf);
void			fdf_info(t_mmlx mlx, t_fdf fdf);
int				fdf_color(t_fdf fdf, double z);
void			fdf_changed(t_fdf *fdf);
void			fdf_help(t_mmlx mlx, t_fdf fdf);
void			fdf_hp(char *key, int x, int fill, t_hp *hp);
void			canvas_point(t_point *a, t_fdf fdf);
#endif
