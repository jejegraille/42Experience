/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diretab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:18:06 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/01 13:02:34 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"
#include <stdlib.h>

char				*form(char *name, char *path, int pf)
{
	char	*tmp;
	char	*form;

	if (pf)
	{
		if (path[1] == '\0' && path[0] == '/')
			form = ft_strjoin(path, name);
		else
		{
			tmp = ft_strjoin(path, "/");
			form = ft_strjoin(tmp, name);
			ft_memdel((void**)&tmp);
		}
	}
	else
		form = ft_strdup(name);
	return (form);
}

char				**ft_diretab(char *d, int path)
{
	DIR				*dd;
	char			**tab;
	struct dirent	*doc;
	size_t			len;

	if ((dd = opendir(d)) == NULL)
		return (NULL);
	len = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * (len + 1));
	doc = readdir(dd);
	tab[len] = doc != NULL ? form(doc->d_name, d, path) : NULL;
	len += doc == NULL ? 0 : 1;
	while (doc != NULL)
	{
		doc = readdir(dd);
		tab = (char **)ft_realloc((void **)&tab, sizeof(char *) * (len + 1));
		tab[len] = doc != NULL ? form(doc->d_name, d, path) : NULL;
		len++;
	}
	closedir(dd);
	return (tab);
}
