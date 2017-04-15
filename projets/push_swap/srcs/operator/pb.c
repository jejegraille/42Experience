/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:36:35 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 17:00:05 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>

void		pb(t_lst **a, t_lst **b)
{
	t_lst	*a1;
	t_lst	*a2;
	t_lst	*b1;

	a1 = *a;
	a2 = a1 == NULL ? NULL : a1->next;
	b1 = *b;
	if (a1 != NULL)
	{
		if (a2 != NULL)
			a2->back = NULL;
		*a = a2;
		if (b1 != NULL)
			b1->back = a1;
		a1->next = b1;
		a1->back = NULL;
		*b = a1;
	}
}
