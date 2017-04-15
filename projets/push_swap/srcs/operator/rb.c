/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:24:19 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 19:12:43 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>

void		rb(t_lst **a, t_lst **b)
{
	t_lst *fe;
	t_lst *le;

	(void)a;
	fe = *b;
	le = *b;
	while (le != NULL && le->next != NULL)
		le = le->next;
	if (fe != NULL && le != NULL && fe != le)
	{
		le->next = fe;
		*b = fe->next;
		(*b)->back = NULL;
		fe->back = le;
		fe->next = NULL;
	}
}
