/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 10:48:36 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 12:52:57 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*second;
	t_list	*first;
	t_list	*tmp;

	first = *begin_list;
	second = first ? first->next : NULL;
	if (first && (*cmp)(first->data, second->data) > 0)
	{
		first->next = second->next;
		second->next = first;
		*begin_list = second;
	}
	while (first)
	{
		tmp = first;
		first = first->next;
		second = first ? first->next : NULL;
		if (second && (*cmp)(first->data, second->data) > 0)
		{
			tmp->next = second;
			first->next = second->next;
			second->next = first;
			first = second;
		}
	}
}
