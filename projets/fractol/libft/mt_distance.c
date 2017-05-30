/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 12:12:25 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/12 12:17:30 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double		mt_distance(double xa, double ya, double xb, double yb)
{
	return (sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya)));
}
