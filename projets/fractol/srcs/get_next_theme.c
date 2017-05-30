/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_theme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:48:02 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/17 16:17:23 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractole.h>
#include <libx.h>

void		set_next_theme(t_graph *gr)
{
	int		max;

	max = 8;
	if (gr->theme == 0)
		gr->rgb = get_rgba(7, 3, 1, 0);
	if (gr->theme == 1)
		gr->rgb = get_rgba(2, 1, 0, 0);
	if (gr->theme == 2)
		gr->rgb = get_rgba(2, 5, 10, 0);
	if (gr->theme == 3)
		gr->rgb = get_rgba(1, 1, 2, 0);
	if (gr->theme == 4)
		gr->rgb = get_rgba(1, 7, 2, 0);
	if (gr->theme == 5)
		gr->rgb = get_rgba(1, 2, 1, 0);
	if (gr->theme == 6)
		gr->rgb = get_rgba(3, 1, 4, 0);
	if (gr->theme == 7)
		gr->rgb = get_rgba(2, 1, 2, 0);
	gr->theme = gr->theme == max - 1 ? 0 : (gr->theme + 1);
}
