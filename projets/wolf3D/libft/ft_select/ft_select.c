/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:14:58 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 12:32:16 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <unistd.h>
#include <fcntl.h>

static void		fts_init(t_fts *data)
{
	g_fts.sig_t = -1;
	data->exit = 0;
	data->select_count = 0;
	data->ok = 0;
	data->page = 0;
	data->curs = 0;
	data->lcurs = -1;
}

char			**ft_select(char **tabl)
{
	t_fts			data;
	extern char		**environ;

	fts_init(&data);
	fts_analys(&data, tabl);
	data.eta = ft_strnew(data.len);
	fts_init_signal();
	tabl = ft_tabsdup(tabl);
	if (tcgetattr(0, &(g_fts.term)) == -1 || fts_set_term() == -1)
		return (fts_error("wrong terminal"));
	if ((data.tname = ft_getvar(environ, "TERM")) == NULL)
		return (fts_error("TERM undefinded"));
	if (tgetent(NULL, data.tname) == -1)
		return (fts_error("getent can't find terminal name"));
	g_fts.fd = open(ttyname(0), O_WRONLY);
	fts_cap("vi");
	while (data.exit == 0 && fts_update(&data, tabl) == 0)
		;
	fts_reset_term();
	fts_reset_signal(1);
	close(g_fts.fd);
	return (fts_final(&data, tabl));
}
