/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:34:08 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:53:07 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <stdlib.h>
#include <string.h>

int		mx_motion_notify(int x, int y, void *param)
{
	t_mouse		*ms;
	t_system	*system;

	system = (t_system *)param;
	ms = system->mouse;
	ms->x = x;
	ms->y = y;
	ms->pos_rel.x = (x / (double)(system->width));
	ms->pos_rel.y = (y / (double)(system->height));
	return (0);
}

int		mx_hook_win_close(void *param)
{
	t_system *sys;

	sys = (t_system *)param;
	if (sys->event_win_close == MX_EXIT)
		exit(0);
	return (0);
}
