/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_final.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:17:43 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/29 12:17:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static char		**selected(t_fts *data, char **tabl)
{
	int		i;
	int		i2;

	i = -1;
	i2 = 0;
	while (++i < data->len)
	{
		if ((data->eta)[i] == '1')
		{
			tabl[i2] = tabl[i];
			i2++;
		}
		else
			ft_memdel((void **)&(tabl[i]));
	}
	tabl[i2] = NULL;
	return (tabl);
}

char			**fts_final(t_fts *data, char **tabl)
{
	int		i;
	char	**res;

	if (data->ok == 0 || data->select_count == 0)
	{
		i = -1;
		while (++i < data->len)
			ft_memdel((void **)&(tabl[i]));
		ft_memdel((void **)&(tabl));
		res = NULL;
	}
	else
		res = selected(data, tabl);
	ft_memdel((void **)&(data->eta));
	return (res);
}
