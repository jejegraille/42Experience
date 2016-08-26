/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 05:59:47 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/26 04:18:01 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*new;
	t_list	*tmp;
	t_list	*begin_list;

	if (ac <= 1)
		return (NULL);
	ac = ac - 1;
	tmp = NULL;
	begin_list = ft_create_elem(av[ac]);
	while (--ac > 0)
	{
		new = ft_create_elem(av[ac]);
		tmp = begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (begin_list);
}
