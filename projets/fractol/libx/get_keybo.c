/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keybo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:13:10 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/17 11:19:39 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <string.h>

t_keybo		*get_keybo(t_keybo *save)
{
	static t_keybo keybo;

	if (save != NULL)
		keybo = *save;
	return (&keybo);
}
