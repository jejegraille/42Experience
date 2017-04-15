/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_gestion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:46:02 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/22 19:42:44 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_ls.h>

t_fl	*fl_new(t_fl *start, char *name)
{
	t_fl	*element;
	t_fl	*tmp;

	element = (t_fl *)malloc(sizeof(t_fl *));
	element->name = name;
	element->next = NULL;
	if (start == NULL)
		return (element);
	else
	{
		tmp = start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = element;
	}
	return (start);
}
