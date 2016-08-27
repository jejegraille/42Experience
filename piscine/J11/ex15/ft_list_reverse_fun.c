/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 11:25:48 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 08:02:35 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void		rev_data(t_list *begin_list, long nb)
{
	t_list	*first;
	t_list	*second;
	void	*data;
	long	i;

	first = begin_list;
	second = first ? first->next : NULL;
	i = -1;
	while (++i < nb - 1 && first && first->next != NULL)
	{
		data = second->data;
		second->data = first->data;
		first->data = data;
		first = first->next;
		second = first ? first->next : NULL;
	}
}

void		ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*first;
	long	count;

	first = begin_list;
	count = 0;
	while (first)
	{
		first = first->next;
		count++;
	}
	while (count > 1)
	{
		rev_data(begin_list, count);
		count--;
	}
}
