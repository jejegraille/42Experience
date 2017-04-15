/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:39:26 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/12 19:41:39 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		mt_tri(t_point a, t_point b, t_point c, t_tri *tri)
{
	mt_point(a.x, a.y, a.z, &(tri->a));
	mt_point(b.x, b.y, b.z, &(tri->b));
	mt_point(c.x, c.y, c.z, &(tri->c));
}
