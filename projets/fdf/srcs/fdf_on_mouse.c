/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_on_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:04:55 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/14 18:52:14 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mmlx.h>
#include <libft.h>

int		fdf_on_mouse(int button, int x, int y, void *control)
{
	t_ctrl *ctrl;

	ctrl = (t_ctrl *)control;
	ctrl->mouse_x = x;
	ctrl->mouse_y = y;
	ctrl->mouse_btn = button;
	ctrl->mouse_time = 0.2;
	return (1);
}
