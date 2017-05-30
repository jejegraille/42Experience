/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 12:37:31 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/14 12:38:51 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

t_rec		get_rec(t_point top_left, t_point bot_right)
{
	t_rec	rec;

	rec.tl = top_left;
	rec.br = bot_right;
	rec.width = bot_right.x - top_left.x;
	rec.height = bot_right.y - top_left.y;
	return (rec);
}
