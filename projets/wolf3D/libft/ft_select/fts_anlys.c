/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_anlys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:18:33 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/22 11:09:07 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	fts_analys(t_fts *data, char **tabl)
{
	int	len;

	data->maxlen = 0;
	data->len = 0;
	while (*tabl)
	{
		len = (int)ft_strlen(*tabl);
		data->maxlen < len && (data->maxlen = len);
		data->len += 1;
		tabl++;
	}
}
