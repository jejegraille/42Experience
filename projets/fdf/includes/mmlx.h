/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmlx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:02:36 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 19:30:54 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MMLX_H
# define MMLX_H

# include <mlx.h>
# include <libft.h>

typedef struct		s_mmlx
{
	void *mlx;
	void *win;
	void *img;
}					t_mmlx;

typedef struct		s_ctrl
{
	int		mouse_x;
	int		mouse_y;
	int		mouse_btn;
	int		last_key;
	double	key_time;
	double	mouse_time;
}					t_ctrl;

void				mmlx_init(t_ctrl *ctrl);
void				mmlx_point(t_mmlx mlx, t_point p, int color);
void				mmlx_line(t_mmlx mlx, t_line ab, int color);
void				mmlx_tri(t_mmlx mlx, t_tri tri, int color);
void				mmlx_line_i(t_mmlx mlx, t_line ab, int color);
void				mmlx_tri_i(t_mmlx mlx, t_tri tri, int color);
void				mmlx_newp(double x, double y, double z, t_point *p);
#endif
