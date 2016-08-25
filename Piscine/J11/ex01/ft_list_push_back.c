/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:39:28 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/25 03:09:01 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*intermediaire;
	t_list	*new;

	new = ft_create_elem(data);
	intermediaire = *begin_list;
	if (intermediaire == NULL)
		*begin_list = new;
	else
		while (intermediaire->next != NULL)
			intermediaire = intermediaire->next;
	if (intermediaire != NULL)
		intermediaire->next = new;
}
