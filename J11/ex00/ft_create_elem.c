/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 07:34:21 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/23 08:22:02 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list		*ft_create_elem(void *data)
{
	t_list	*new_element;

	new_element = malloc(sizeof(struct s_list));
	new_element->data = data;
	new_element->next = NULL;
	return (new_element);
}
