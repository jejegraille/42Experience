/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:23:59 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 13:24:47 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>

void		sb(t_lst **a, t_lst **b)
{
	t_lst	*b1;
	t_lst	*b2;

	(void)a;
	b1 = *b;
	if (b1 != NULL)
		b2 = b1->next;
	if (b1 != NULL && b2 != NULL)
	{
		b1->next = b2->next;
		b1->back = b2;
		if (b2->next)
			b2->next->back = b1;
		b2->next = b1;
		b2->back = NULL;
		*b = b2;
	}
}
