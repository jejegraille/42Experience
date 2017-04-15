/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushtabs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:28:40 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/25 18:26:36 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pushtabs(char ***tab, char *str)
{
	char	**new;
	size_t	len;
	size_t	i;

	len = 1 + ft_tablen((void **)(*tab));
	new = ft_memalloc(sizeof(char *) * (len + 1));
	i = 0;
	while (i < len - 1)
	{
		new[i] = (*tab)[i];
		i++;
	}
	new[len] = NULL;
	new[len - 1] = str;
	ft_memdel((void **)tab);
	*tab = new;
}
