/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:04:24 by jgraille          #+#    #+#             */
/*   Updated: 2016/12/11 16:03:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_realloc(void **ptr, size_t buff)
{
	void	*freshptr;

	if (!(freshptr = (void *)ft_memalloc(buff)))
		return (NULL);
	ft_memcpy(freshptr, *ptr, buff);
	ft_memdel(ptr);
	return (freshptr);
}
