/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 07:07:43 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 15:54:45 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*first;
	t_list	*tmp;
	t_list	*new;

	first = *begin_list;
	new = ft_create_elem(data);
	if (first == NULL || (*cmp)(first->data, data) > 0)
	{
		if (first)
			new->next = first;
		*begin_list = new;
		return ;
	}
	while (first)
	{
		tmp = first;
		first = first->next;
		if (first && (*cmp)(first->data, data) > 0)
		{
			tmp->next = new;
			new->next = first;
			return ;
		}
		tmp->next = first ? tmp->next : new;
	}
}
