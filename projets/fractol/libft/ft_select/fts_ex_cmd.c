/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_ex_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:08:26 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/29 12:15:26 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <unistd.h>

static void			del_ind(t_fts *data, char **tabl)
{
	int i;

	i = data->curs;
	(data->eta[i] == '1') && (data->select_count -= 1);
	ft_memdel((void **)&(tabl[i]));
	while (i < data->len)
	{
		tabl[i] = tabl[i + 1];
		data->eta[i] = data->eta[i + 1];
		i++;
	}
	data->len = data->len - 1;
	tabl[data->len] = NULL;
	if (data->len > 0)
		fts_analys(data, tabl);
	else
		data->exit = 1;
}

static void			del_doublon(t_fts *d, char **tabl)
{
	int i;
	int	i2;
	int	c;

	i = -1;
	while (++i < d->len)
	{
		i2 = 0;
		c = 0;
		while (i2 < d->len && i2 < i - c)
		{
			if (ft_strcmp(tabl[i - c], tabl[i2]) == 0)
			{
				d->curs = i2;
				(d->eta)[i - c] = (d->eta[i - c] || d->eta[i2]) ? '1' : '\0';
				del_ind(d, tabl);
				c++;
			}
			else
				i2++;
		}
		i -= c;
	}
	d->curs = 0;
}

static void			move_ind(int cmd, t_fts *data)
{
	int	curs;
	int	rang;

	curs = data->curs;
	data->lcurs = curs;
	if (cmd == 1067)
		curs = (curs + 1 < data->len) ? curs + 1 : 0;
	if (cmd == 1068)
		curs = (curs - 1 >= 0) ? curs - 1 : (data->len - 1);
	if (cmd == 1065)
	{
		rang = curs % data->tw;
		curs -= data->tw;
		while (curs < 0 || curs % data->tw != rang)
			curs = curs < 0 ? data->len - 1 : (curs - 1);
	}
	if (cmd == 1066)
	{
		rang = curs % data->tw;
		curs += data->tw;
		while (curs >= data->len || curs % data->tw != rang)
			curs = curs >= data->len ? 0 : (curs + 1);
	}
	data->curs = curs;
}

static void			cmd_ca(t_fts *data)
{
	int		i;
	int		ok;
	int		len;
	char	*state;

	len = data->len;
	state = data->eta;
	ok = 0;
	i = 0;
	while (state[i])
		i++;
	ok = len == i ? 1 : 0;
	data->select_count = ok ? 0 : len;
	if (ok == 0)
		ft_memset(state, '1', len);
	else
		ft_memset(state, '\0', len);
}

void				fts_ex_cmd(int cmd, t_fts *data, char **tabl)
{
	if (cmd == 999)
		fts_signal(data);
	if (cmd >= 1065 && cmd <= 1068)
		move_ind(cmd, data);
	if (cmd == 1000)
		data->exit = 1;
	if (cmd == 1072 || cmd == 1070)
	{
		data->lcurs = data->curs;
		data->curs = cmd == 1072 ? 0 : data->len - 1;
	}
	if (cmd == 1001)
		del_ind(data, tabl);
	if (cmd == 1002)
	{
		data->ok = 1;
		data->exit = 1;
	}
	if (cmd == 32)
		fts_cmd_select(data);
	if (cmd == 1)
		cmd_ca(data);
	if (cmd == 4)
		del_doublon(data, tabl);
}
