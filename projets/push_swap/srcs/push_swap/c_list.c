/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:14:46 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/08 13:19:46 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		add_clst(t_clst **start, char c)
{
	t_clst *new;
	t_clst *tmp;

	new = (t_clst *)ft_memalloc(sizeof(t_clst));
	new->c = c;
	new->next = NULL;
	if (*start == NULL)
		*start = new;
	else
	{
		tmp = *start;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
