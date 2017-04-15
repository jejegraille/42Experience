/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:44:17 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/01 13:43:38 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>

void	del_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	del_files(t_lfd **files)
{
	int		i;

	i = 0;
	while (files[i])
	{
		free((files[i])->lname);
		free((files[i])->name);
		free(files[i++]);
	}
	free(files);
}
