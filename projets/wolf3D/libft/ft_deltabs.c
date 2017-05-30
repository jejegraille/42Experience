/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:37:59 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/14 14:28:34 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_deltabs(char **tab)
{
	char **tmp;

	tmp = tab;
	while (*tmp)
		ft_memdel((void **)(tmp++));
	ft_memdel((void **)(&tab));
}
