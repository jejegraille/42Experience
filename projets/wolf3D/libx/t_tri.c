/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:12:48 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/10 15:17:59 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

t_tri		get_tri(t_point a, t_point b, t_point c)
{
	t_tri	tri;

	tri.a = get_point(a.x, a.y, a.z);
	tri.b = get_point(b.x, b.y, b.z);
	tri.c = get_point(c.x, c.y, c.z);
	return (tri);
}
