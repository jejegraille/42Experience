/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:43:56 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/14 19:45:45 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		fdf_hp(char *key, int x, int fill, t_hp *p)
{
	p->fill = fill;
	p->x = x;
	p->key = key;
}
