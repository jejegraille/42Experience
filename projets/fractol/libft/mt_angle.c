/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 11:31:53 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 17:07:27 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double		mt_angle(double xa, double ya, double xb, double yb)
{
	double x;
	double y;

	x = xb - xa;
	y = yb - ya;
	return (atan2(y, x));
}
