/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokent_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:06:08 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/22 19:37:23 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static size_t		chrstart(char *list, char sep, int index)
{
	size_t	start;
	size_t	i;
	int		ind;

	i = 0;
	ind = 0;
	start = 0;
	while (list[i] && ind != index)
	{
		if (list[i] == sep)
		{
			start = i + 1;
			ind++;
		}
		i++;
	}
	return (start);
}

static size_t		chrend(char *list, char sep)
{
	size_t i;

	i = 0;
	while (list[i] && list[i] != sep)
		i++;
	return (i);
}

char				*ft_token_at(char *list, char sep, int index)
{
	size_t	start;
	size_t	end;

	if (list != NULL)
	{
		start = chrstart(list, sep, index);
		end = chrend(list + start, sep);
		return (ft_strsub(list, start, end));
	}
	return (list);
}
