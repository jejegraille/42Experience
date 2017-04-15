/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:50:39 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/08 18:53:14 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			exec_algo(t_lst **a, t_lst **b, int count)
{
	char *res;
	char *tmp;

	res = NULL;
	if (count < 7)
		res = brute_swap(a, b, count);
	else
		res = mind_swap(a, b, count);
	tmp = res;
	while (*res)
	{
		ft_putendl(str_act(*res));
		res++;
	}
	if (tmp != NULL)
		ft_memdel((void **)&tmp);
}
