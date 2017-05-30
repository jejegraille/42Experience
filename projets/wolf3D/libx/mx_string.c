/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:31:27 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 16:36:38 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

void		mx_string(char *str, t_point o, int color)
{
	t_mx *mx;

	mx = get_mx(NULL);
	mlx_string_put(mx->id, mx->win, o.x, o.y, color, str);
}
