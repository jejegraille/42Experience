/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 12:39:49 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 12:41:00 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractole.h>
#include <libft.h>

void			change_view(t_graph *gr, t_point center, double sx, double sy)
{
	gr->center = center;
	gr->center_d = center;
	gr->scale.x = sx;
	gr->scale.y = sy;
	gr->scale_d = gr->scale;
}
