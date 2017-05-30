/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_system.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:48:58 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/17 12:50:29 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <string.h>

t_system		*get_system(t_system *save)
{
	static	t_system system;

	if (save != NULL)
		system = *save;
	return (&system);
}
