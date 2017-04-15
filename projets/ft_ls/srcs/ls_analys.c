/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_analys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:05:31 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/04 15:13:30 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>

void		init_ls_analys(t_align *al)
{
	al->usr = 0;
	al->grp = 0;
	al->size = 0;
	al->link = 0;
	al->total = 0;
	al->count = 0;
}

static int	size(t_lfd *file)
{
	if (file->type == 'c' || file->type == 'b')
		return (8);
	else
		return (ft_nbrlen(file->size));
}

void		ls_analys(t_lfd *file, t_align *al, t_ls ls)
{
	int		tmp;

	if (file->analysed == 0)
	{
		file->analysed = 1;
		file->valide = 0;
		if (valf(*file, ls))
		{
			tmp = ft_strlen(file->usr);
			al->usr = tmp > al->usr ? tmp : al->usr;
			tmp = ft_strlen(file->grp);
			al->grp = tmp > al->grp ? tmp : al->grp;
			tmp = size(file);
			al->size = tmp > al->size ? tmp : al->size;
			tmp = ft_nbrlen(file->link);
			al->link = tmp > al->link ? tmp : al->link;
			al->total += file->bsize;
			(al->count)++;
			file->valide = 1;
		}
	}
}
