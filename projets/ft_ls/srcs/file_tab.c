/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 17:11:08 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/04 19:49:34 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

static char			wath_time(t_ls ls)
{
	if (ls.t > 1)
		return (ls.t == 2 ? 'a' : 'c');
	return ('m');
}

static void			error_file(char *name, void **del, t_sls *sls)
{
	sls->ok = 1;
	ft_putstr_fd("ft_ls:", 2);
	perror(name);
	ft_memdel((void **)del);
}

t_lfd				**file_tab(char **tab, t_ls *ls, t_align *al, t_sls *sls)
{
	t_lfd	*tmp;
	t_lfd	**fi;

	ls->len = 0;
	fi = (t_lfd **)ft_memalloc(sizeof(t_lfd *) * (ls->len + 1));
	while (*tab)
	{
		tmp = (t_lfd *)ft_memalloc(sizeof(t_lfd));
		if (ls_filed(*tab, tmp, wath_time(*ls)) != -1)
		{
			(fi[ls->len] = tmp) && (ls->len)++;
			ls_analys(tmp, al, *ls);
			fi = (t_lfd **)ft_realloc((void **)&fi,
				sizeof(t_lfd *) * (ls->len + 1));
		}
		else
			error_file(*tab, (void **)&tmp, sls);
		tab++;
	}
	fi[ls->len] = NULL;
	return (fi);
}
