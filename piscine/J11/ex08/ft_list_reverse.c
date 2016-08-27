/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 07:42:37 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 12:02:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list	*first;
	t_list	*back;
	t_list	*tmp;

	first = *begin_list;
	tmp = first;
	if (first)
	{
		first = first->next;
		tmp->next = NULL;
	}
	while (first)
	{
		back = first;
		first = first->next;
		back->next = tmp;
		tmp = back;
	}
	*begin_list = tmp;
}
