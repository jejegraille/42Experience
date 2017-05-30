/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_par.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:03:21 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/24 15:07:01 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractole.h>
#include <string.h>

t_par		*get_par(t_par *save)
{
	static t_par par;

	if (save != NULL)
		par = *save;
	return (&par);
}
