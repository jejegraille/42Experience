/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:10:19 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 19:12:53 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>

void		rra(t_lst **a, t_lst **b)
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
		le->back->next = NULL;
		le->back = NULL;
		le->next = fe;
		fe->back = le;
		*a = le;
	}
}
