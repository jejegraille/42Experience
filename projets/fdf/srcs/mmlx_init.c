/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmlx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:53:56 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/14 18:51:54 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mmlx.h>

void	mmlx_init(t_ctrl *ctrl)
{
	ctrl->mouse_x = -1;
	ctrl->mouse_y = -1;
	ctrl->mouse_btn = 0;
	ctrl->mouse_time = 0;
	ctrl->last_key = -1;
	ctrl->key_time = 0;
}
