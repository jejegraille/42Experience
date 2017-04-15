/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:40:01 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 19:11:36 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>

void		ra(t_lst **a, t_lst **b)
{
	t_lst *fe;
	t_lst *le;

	(void)b;
	fe = *a;
	le = *a;
	while (le != NULL && le->next != NULL)
		le = le->next;
	if (fe != NULL && le != NULL && fe != le)
	{
		le->next = fe;
		*a = fe->next;
		(*a)->back = NULL;
		fe->back = le;
		fe->next = NULL;
	}
}
