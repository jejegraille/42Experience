/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 11:17:58 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/01 11:29:59 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>

void		add_elem(t_lst **start, t_lst *elem)
{
	t_lst *tmp;

	if (*start == NULL)
		*start = elem;
	else
	{
		tmp = *start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = elem;
		elem->back = tmp;
	}
}
