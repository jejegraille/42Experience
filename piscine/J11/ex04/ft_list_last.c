/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 02:33:45 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 08:06:42 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list		*ft_list_last(t_list *begin_list)
{
	t_list *last;

	last = begin_list;
	if (begin_list != NULL)
		while (last->next != NULL)
			last = last->next;
	return (last);
}
