/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:23:13 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/14 18:06:32 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		mt_line(t_point pa, t_point pb, t_line *line)
{
	double u;
	double v;

	u = pb.x - pa.x;
	v = pb.y - pa.y;
	line->a = -v;
	line->b = u;
	line->c = v * pa.x - u * pa.y;
	mt_point(pa.x, pa.y, 0, &(line->pa));
	mt_point(pb.x, pb.y, 0, &(line->pb));
	line->l = mt_distance(pa.x, pa.y, pb.x, pb.y);
}
