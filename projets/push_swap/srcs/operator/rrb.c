/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:27:39 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 19:13:02 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>

void		rrb(t_lst **a, t_lst **b)
{
	t_lst *fe;
	t_lst *le;

	(void)a;
	fe = *b;
	le = *b;
	while (le != NULL && le->next != NULL)
		le = le->next;
	if (fe != NULL && le != NULL && le != fe)
	{
		le->back->next = NULL;
		le->back = NULL;
		le->next = fe;
		fe->back = le;
		*b = le;
	}
}
