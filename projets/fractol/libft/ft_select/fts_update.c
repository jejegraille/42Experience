/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:17:32 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/22 14:34:25 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int			check_term(t_fts *data)
{
	int	marge;

	if (tgetent(NULL, data->tname) == -1)
		return (-1);
	marge = 3;
	data->w = tgetnum("co");
	data->h = tgetnum("li");
	data->tw = data->w / (data->maxlen + marge);
	(data->tw == 0) && (data->tw = 1);
	data->cw = data->w / (data->tw < data->len ? data->tw : data->len);
	if (data->cw == 0)
		return (-1);
	return (0);
}

int					fts_update(t_fts *data, char **tabl)
{
	int	cmd;

	if (check_term(data) == -1)
		return (-1);
	fts_print(data, tabl);
	cmd = fts_read();
	fts_ex_cmd(cmd, data, tabl);
	return (0);
}
