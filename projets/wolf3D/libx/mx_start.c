/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:44:28 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 09:06:43 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <stdlib.h>

int		mx_hook_m(int button, int x, int y, void *param)
{
	t_mouse *m;

	(void)param;
	m = get_mouse(NULL);
	m->x = x;
	m->y = y;
	m->click = button;
	return (0);
}

int		mx_hook_l(void *param)
{
	t_system	*system;

	system = (t_system *)param;
	mx_loop(system);
	if (system->render_off != 1)
		mx_render(system->mx);
	system->mouse->click = 0;
	system->keybo->onkey = 0;
	system->keybo->key = 0;
	return (0);
}

void	mx_start(void)
{
	t_system	*s;

	s = get_system(NULL);
	s->mx = get_mx(NULL);
	s->width = s->mx->width;
	s->height = s->mx->height;
	s->mouse = get_mouse(NULL);
	s->keybo = get_keybo(NULL);
	s->keybo->down = NULL;
	mlx_mouse_hook(s->mx->win, &mx_hook_m, NULL);
	mlx_loop_hook(s->mx->id, &mx_hook_l, (void *)(s));
	mlx_hook(s->mx->win, DESTROYNOTIFY,
			STRUCTURENOTIFYMASK, &mx_hook_win_close, (void *)s);
	mlx_hook(s->mx->win, MOTIONNOTIFY,
			POINTERMOTIONMASK, &mx_motion_notify, (void *)s);
	mlx_hook(s->mx->win, KEYRELEASE,
			KEYRELEASEMASK, &mx_keybo_release, (void*)(s->keybo));
	mlx_hook(s->mx->win, KEYPRESS,
			BUTTONPRESSMASK, &mx_hook_k, (void*)(s->keybo));
	mlx_loop(s->mx->id);
}
