/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 07:30:39 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 08:30:41 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*search;

	i = 0;
	search = begin_list;
	while (search && i < nbr)
	{
		search = search->next;
		i++;
	}
	if (i != nbr)
		search = NULL;
	return (search);
}
