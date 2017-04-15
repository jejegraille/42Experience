/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remtabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:45:13 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/14 12:50:42 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_remtabs(char ***tab, size_t ind)
{
	size_t	len;
	size_t	i;
	char	**tmp;

	len = ft_tablen((void **)(*tab));
	if (ind < len)
	{
		tmp = (char **)ft_memalloc(sizeof(char *) * (len));
		i = 0;
		while (i < ind)
		{
			tmp[i] = (*tab)[i];
			i++;
		}
		ft_memdel((void *)((*tab) + i));
		i++;
		while (i < len)
		{
			tmp[i - 1] = (*tab)[i];
			i++;
		}
		tmp[len - 1] = NULL;
		ft_memdel((void **)tab);
		*tab = tmp;
	}
}
