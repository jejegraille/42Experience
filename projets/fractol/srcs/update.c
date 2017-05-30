/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:42:53 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 13:01:28 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractole.h>
#include <string.h>
#include <libft.h>
#include <stdio.h>

static void		keybo_action(int key, t_graph *gr)
{
	if (mx_key_down(K_LEFT) || mx_key_down(0))
		gr->center_d.x -= 20 * gr->scale_d.x;
	if (mx_key_down(K_RIGHT) || mx_key_down(2))
		gr->center_d.x += 20 * gr->scale_d.x;
	if (mx_key_down(K_UP) || mx_key_down(13))
		gr->center_d.y -= 20 * gr->scale_d.y;
	if (mx_key_down(K_DOWN) || mx_key_down(1))
		gr->center_d.y += 20 * gr->scale_d.y;
	if (key == 69)
		gr->it_max = gr->it_max >= 300 ? 300 : (gr->it_max + 10);
	if (key == 78)
		gr->it_max = gr->it_max <= 10 ? 10 : (gr->it_max - 10);
	if (key == 17)
		set_next_theme(gr);
	if (key == 3)
		get_next_fct(gr);
	if (key == 35)
		gr->debug = !(gr->debug);
	if (key == 49)
		gr->mouse_var = !(gr->mouse_var);
	if (key == 45)
		nextview(gr);
	if (key == 53)
		exit(0);
}

static void		mouse_action(t_system *sys, int button, t_graph *gr)
{
	t_point	d;
	int		recenter;

	d.x = sys->mouse->x - (sys->mx->width / 2);
	d.y = sys->mouse->y - (sys->mx->height / 2);
	recenter = 0;
	if (button == 4)
	{
		recenter = 1;
		gr->scale_d.x *= 0.7;
		gr->scale_d.y *= 0.7;
	}
	if (button == 5)
	{
		recenter = 1;
		gr->scale_d.x *= 1.3;
		gr->scale_d.y *= 1.3;
		d.x *= -1;
		d.y *= -1;
	}
	if (recenter)
	{
		gr->center_d.x += (d.x * gr->scale.x) - (d.x * gr->scale_d.x);
		gr->center_d.y += (d.y * gr->scale.y) - (d.y * gr->scale_d.y);
	}
}

void			update(t_graph *gr)
{
	t_system	*system;

	system = get_system(NULL);
	if (system->mouse->click)
		mouse_action(system, system->mouse->click, gr);
	if (system->keybo->onkey || system->keybo->keycount)
		keybo_action(system->keybo->key, gr);
	if (gr->mouse_var == 0)
		gr->mouse_r = system->mouse->pos_rel;
	gr->scale.x = gr->scale.x + (gr->scale_d.x - gr->scale.x) * 25 * 0.016;
	gr->scale.y = gr->scale.y + (gr->scale_d.y - gr->scale.y) * 25 * 0.016;
	gr->center.x = gr->center.x + (gr->center_d.x - gr->center.x) * 25 * 0.016;
	gr->center.y = gr->center.y + (gr->center_d.y - gr->center.y) * 25 * 0.016;
}
