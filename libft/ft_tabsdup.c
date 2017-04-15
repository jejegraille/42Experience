/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:31:36 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/22 12:31:39 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabsdup(char **tab)
{
	size_t	len;
	size_t	i;
	char	**new_tab;

	len = ft_tablen((void **)tab);
	new_tab = (char **)ft_memalloc(sizeof(char *) * len + 1);
	i = 0;
	while (i < len)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[len] = NULL;
	return (new_tab);
}
