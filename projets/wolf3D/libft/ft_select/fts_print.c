/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:39:45 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/29 12:15:52 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		short_str(char *str, int maxlen)
{
	int		len;

	len = (int)ft_strlen(str);
	if (len > maxlen && maxlen >= 3)
	{
		str[maxlen - 3] = '.';
		str[maxlen - 2] = '.';
		str[maxlen - 1] = '.';
		str[maxlen] = '\0';
	}
}

static char		*full_str(char *str, char select, int curs, int maxlen)
{
	char *tmp;

	str = ft_strdup(str);
	short_str(str, maxlen);
	if (select)
	{
		tmp = ft_strjoin("\x1B[7m", str);
		ft_memdel((void **)&str);
		str = tmp;
	}
	if (curs)
	{
		tmp = ft_strjoin("\x1B[4m", str);
		ft_memdel((void **)&str);
		str = tmp;
	}
	tmp = ft_strjoin(str, "\x1B[0m");
	ft_memdel((void **)&str);
	str = tmp;
	return (str);
}

static void		p_all(t_fts *d, char **tabl, int *y, int nbr)
{
	int		i;
	int		x;
	int		h;
	char	*elem;
	char	*tmp;

	i = -1;
	while (tabl[++i])
	{
		if (i >= d->page * nbr && i < (d->page + 1) * nbr)
		{
			x = d->cw * (i % d->tw);
			*y = (i % nbr) / d->tw;
			elem = full_str(tabl[i], (d->eta)[i], (d->curs == i), d->cw);
			fts_cap_write(elem, x, *y);
			ft_memdel((void **)&elem);
		}
	}
	h = nbr >= d->len ? *y + 2 : d->h - 1;
	fts_cap_write((tmp = ft_itoa(d->page)), 0, h - 1);
	ft_memdel((void **)&tmp);
	fts_cap_write("/", ft_nbrlen(d->page), h - 1);
	tmp = ft_itoa(d->len / nbr);
	fts_cap_write(tmp, ft_nbrlen(d->page) + 1, h - 1);
	ft_memdel((void **)&tmp);
}

static void		p_one(t_fts *d, char **tabl, int *y, int nbr)
{
	char	*elem;
	int		count;
	int		x;
	int		i;

	count = -1;
	while (++count < 2)
	{
		i = count == 0 ? d->lcurs : d->curs;
		if (i >= d->page * nbr && i < (d->page + 1) * nbr)
		{
			x = d->cw * (i % d->tw);
			*y = (i % nbr) / d->tw;
			elem = full_str(tabl[i], (d->eta)[i], (d->curs == i), d->cw);
			fts_cap_write(elem, x, *y);
			ft_memdel((void **)&elem);
		}
	}
}

void			fts_print(t_fts *data, char **tabl)
{
	int		y;
	int		nbr;
	int		page;

	nbr = data->tw * (data->h - 2);
	nbr == 0 && (nbr = 1);
	page = data->curs / nbr;
	if (page != data->page || data->lcurs == -1)
	{
		fts_cap("cd");
		data->page = page;
		p_all(data, tabl, &y, nbr);
	}
	else
	{
		data->page = page;
		p_one(data, tabl, &y, nbr);
	}
	data->lcurs = -1;
}
