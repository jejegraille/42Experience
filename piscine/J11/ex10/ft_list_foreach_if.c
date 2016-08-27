/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 08:57:45 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 09:07:28 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list	*explorer;

	explorer = begin_list;
	while (explorer)
	{
		if (!(*cmp)(explorer->data, data_ref))
			(*f)(explorer->data);
		explorer = explorer->next;
	}
}
