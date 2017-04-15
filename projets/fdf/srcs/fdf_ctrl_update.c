/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_ctrl_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 20:06:55 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/14 18:54:21 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		fdf_ctrl_update(t_ctrl *ctrl)
{
	ctrl->key_time = ctrl->key_time > 0 ? ctrl->key_time - 0.016 : 0;
	ctrl->mouse_time = ctrl->mouse_time > 0 ? ctrl->mouse_time - 0.016 : 0;
	ctrl->last_key = ctrl->key_time == 0 ? -1 : ctrl->last_key;
	ctrl->mouse_btn = ctrl->mouse_time == 0 ? -1 : ctrl->mouse_btn;
}
