/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 12:01:58 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/05 17:56:04 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ft_printf.h>

static void			error_dir(char *name, t_sls *sls)
{
	sls->ok = 1;
	ft_putstr_fd("ft_ls:", 2);
	perror(name);
}

static void			ft_ls_dir(t_fl *list, t_ls ls, t_sls *sls)
{
	char		**tmp_tab;
	int			f;
	t_fl		*tmp;

	f = ls.first;
	ls.first = 0;
	while (list != NULL)
	{
		ft_putstr(sls->tmpcount ? "\n" : "");
		if (!(ls.path) && !(ls.only && !(sls->tmpcount)) &&
				((ls.rec && !f) || (f && ls.len > 1)))
			ft_printf("%s:\n", list->name);
		if ((tmp_tab = ft_diretab(list->name, 1)) == NULL)
			error_dir(list->name, sls);
		else
		{
			ft_ls(tmp_tab, ls, list->name, sls);
			del_tab(tmp_tab);
		}
		tmp = list;
		list = list->next;
		ft_memdel((void **)&tmp);
	}
}

static t_fl			*ls_print(t_lfd **files, t_ls ls, t_align al, t_sls *sls)
{
	t_fl	*list;
	int		i;

	i = 0;
	list = NULL;
	sls->tmpcount = 0;
	while (files[i])
	{
		if (files[i]->type == 'd' && (vald(*(files[i]), ls) || ls.first))
			list = fl_new(list, files[i]->path);
		if (files[i]->valide)
		{
			sls->count += 1;
			sls->tmpcount += 1;
			print_filed(*(files[i]), ls, al);
		}
		i++;
	}
	return (list);
}

void				ft_ls(char **tab, t_ls ls, char *path, t_sls *sls)
{
	t_lfd		**files;
	t_fl		*list;
	t_align		al;

	init_ls_analys(&al);
	(void)path;
	files = file_tab(tab, &ls, &al, sls);
	sort_tab(files, ls);
	if (!(ls.path) && !(ls.first) && al.count > 0 && ls.l && !(ls.only))
		ft_printf("total %d\n", al.total);
	list = ls_print(files, ls, al, sls);
	if (list != NULL)
		ft_ls_dir(list, ls, sls);
	del_files(files);
}
