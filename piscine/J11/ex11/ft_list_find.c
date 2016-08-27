/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 09:54:05 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 09:10:00 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list		*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*search;

	search = begin_list;
	while (search)
	{
		if (!((*cmp)(search->data, data_ref)))
			return (search);
		search = search->next;
	}
	return (NULL);
}
