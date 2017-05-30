/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:07:25 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 12:26:07 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractole.h>
#include <string.h>

void		reset_graph(t_graph *gr)
{
	t_mx *mx;

	mx = get_mx(NULL);
	set_screen(gr);
	gr->it_max = 200;
	gr->view = 0;
	gr->debug = 0;
	gr->scale = get_point(gr->screen.width / mx->width,
			gr->screen.height / mx->height, 0);
	gr->scale_d = gr->scale;
	gr->center = get_point(gr->screen.tl.x + (mx->width / 2) * gr->scale.x,
			gr->screen.tl.y + (mx->height / 2) * gr->scale.y, 0);
	gr->center_d = gr->center;
}

void		init_graph(t_graph *gr)
{
	t_mx	*mx;

	mx = get_mx(NULL);
	gr->init = 1;
	gr->it_max = 150;
	gr->debug = 0;
	gr->fct_nbr -= 1;
	get_next_fct(gr);
	gr->scale = get_point(gr->screen.width / mx->width,
			gr->screen.height / mx->height, 0);
	gr->scale_d = gr->scale;
	gr->center = get_point(gr->screen.tl.x + gr->screen.width / 2,
			gr->screen.tl.y + gr->screen.height / 2, 0);
	gr->center_d = gr->center;
	set_next_theme(gr);
}

void		set_screen(t_graph *gr)
{
	if (gr->fct_nbr == 0)
		gr->screen = get_rec(get_point(-2.1, -1.2, 0), get_point(0.6, 1.1, 0));
	if (gr->fct_nbr == 1)
		gr->screen = get_rec(get_point(-1.5, -1.7, 0), get_point(1.5, 1.4, 0));
	if (gr->fct_nbr == 2)
		gr->screen = get_rec(get_point(-2, -2, 0), get_point(1.3, 1.1, 0));
	if (gr->fct_nbr == 3)
		gr->screen = get_rec(get_point(-2.2, -1.5, 0), get_point(1.4, 1.5, 0));
	if (gr->fct_nbr == 4)
		gr->screen = get_rec(get_point(-5, -3, 0), get_point(2.8, 2.6, 0));
}

void		get_next_fct(t_graph *gr)
{
	int	max;

	max = 5;
	gr->fct_nbr += 1;
	(gr->fct_nbr == max) && (gr->fct_nbr = 0);
	if (gr->fct_nbr == 0)
		gr->fct = &fct_mandelbrot;
	if (gr->fct_nbr == 1)
		gr->fct = &fct_julia;
	if (gr->fct_nbr == 2)
		gr->fct = &fct_burning_ship;
	if (gr->fct_nbr == 3)
		gr->fct = &fct_burning_bird;
	if (gr->fct_nbr == 4)
		gr->fct = &fct_fusee;
	reset_graph(gr);
}
