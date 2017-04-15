/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:12:46 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 13:23:22 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>

void		sa(t_lst **a, t_lst **b)
{
	t_lst	*a1;
	t_lst	*a2;

	(void)b;
	a1 = *a;
	if (a1 != NULL)
		a2 = a1->next;
	if (a1 != NULL && a2 != NULL)
	{
		a1->next = a2->next;
		a1->back = a2;
		if (a2->next)
			a2->next->back = a1;
		a2->next = a1;
		a2->back = NULL;
		*a = a2;
	}
}
