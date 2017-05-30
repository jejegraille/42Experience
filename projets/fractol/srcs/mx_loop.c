/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:54:26 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 09:41:38 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <fractole.h>
#include <string.h>

void		mx_loop(t_system *system)
{
	static t_graph	gr;
	t_par			*par;

	system->render_off = 1;
	system->event_win_close = MX_EXIT;
	if (gr.init == 0)
	{
		par = get_par(NULL);
		gr.fct_nbr = par->fractale;
		init_graph(&gr);
	}
	update(&gr);
	frac_loop(system, &gr);
}
