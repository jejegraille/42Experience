/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:28:56 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:53:51 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <string.h>

t_mouse		*get_mouse(t_mouse *save)
{
	static t_mouse	mouse;

	if (save != NULL)
		mouse = *save;
	return (&mouse);
}
