/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 10:01:21 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 12:43:00 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*second;
	t_list	*first;
	t_list	*back;

	first = *begin_list;
	if (first && !((*cmp)(first->data, data_ref)))
	{
		back = first->next;
		free(first);
		*begin_list = back;
		ft_list_remove_if(begin_list, data_ref, cmp);
		return ;
	}
	while (first)
	{
		back = first;
		first = first->next;
		second = first ? first->next : NULL;
		if (first && !((*cmp)(first->data, data_ref)))
		{
			free(first);
			back->next = second;
			first = back;
		}
	}
}
