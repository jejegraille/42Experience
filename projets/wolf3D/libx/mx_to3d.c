/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_to3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:13:30 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:39:22 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

t_point		mx_to3d(t_point a)
{
	t_point c;
	t_point	center;

	center = get_point(320, 320, 0);
	c.z = a.z;
	c.x = a.x - a.z * (center.x - a.x);
	c.y = a.y - a.z * (center.y - a.y);
	return (c);
}
