/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_cmd_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:59:08 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/29 12:14:22 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		fts_cmd_select(t_fts *data)
{
	int curs;

	curs = data->curs;
	data->eta[curs] = data->eta[curs] ? '\0' : '1';
	data->select_count += data->eta[curs] == '1' ? 1 : -1;
	data->lcurs = curs;
	data->curs = (curs + 1 < data->len) ? curs + 1 : 0;
}
