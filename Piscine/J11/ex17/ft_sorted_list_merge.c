/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 07:13:44 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 15:55:59 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_insert(t_list **begin_list, t_list *new, int (*cmp)())
{
	t_list	*first;
	t_list	*tmp;

	first = *begin_list;
	if (first == NULL || (*cmp)(first->data, new->data) > 0)
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
		if (first && (*cmp)(first->data, new->data) > 0)
		{
			tmp->next = new;
			new->next = first;
			return ;
		}
		tmp->next = first ? tmp->next : new;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	t_list	*new;

	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
		while (begin_list2)
		{
			new = begin_list2;
			new->next = NULL;
			ft_insert(begin_list1, new, cmp);
			begin_list2 = begin_list2->next;
		}
}
