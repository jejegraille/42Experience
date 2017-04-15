/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:46:05 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 16:46:08 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int			check_order(t_lst *a, t_lst *b)
{
	int		ok;
	int		min;

	ok = 1;
	if (b != NULL)
		return (0);
	(a != NULL) && (min = a->nb);
	while (ok && a != NULL)
	{
		min > a->nb && (ok = 0);
		min = a->nb;
		a = a->next;
	}
	return (ok);
}
