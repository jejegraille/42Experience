/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 10:36:51 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 09:24:06 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *soudure;

	soudure = *begin_list1;
	if (soudure == NULL)
		*begin_list1 = begin_list2;
	else
	{
		while (soudure->next != NULL)
			soudure = soudure->next;
		soudure->next = begin_list2;
	}
}
