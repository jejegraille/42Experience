/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:13:41 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/10 15:33:35 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

t_line		get_line(t_point pa, t_point pb)
{
	t_line line;
	double u;
	double v;

	u = pb.x - pa.x;
	v = pb.y - pa.y;
	line.a = -v;
	line.b = u;
	line.c = v * pa.x - u * pa.y;
	line.pa = get_point(pa.x, pa.y, 0);
	line.pb = get_point(pb.x, pb.y, 0);
	line.l = get_distance(pa, pb);
	return (line);
}
