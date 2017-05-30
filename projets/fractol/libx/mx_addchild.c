/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_addchild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 11:13:19 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:53:27 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <libft.h>

t_child		*new_child(t_image *image)
{
	t_child	*new;

	new = (t_child *)ft_memalloc(sizeof(t_child));
	new->next = NULL;
	new->image = image;
	return (new);
}

int			mx_addchild(t_image *parent, t_image *child)
{
	t_child		*elem;
	t_child		*tmp;

	if (child->parent != NULL)
		return (-1);
	else
	{
		child->parent = parent;
		elem = new_child(child);
		if (parent->child == NULL)
			parent->child = elem;
		else
		{
			tmp = parent->child;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = elem;
		}
	}
	return (1);
}
