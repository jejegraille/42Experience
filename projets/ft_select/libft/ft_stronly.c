/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:20:51 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/31 12:50:31 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_stronly(char *str, char *list)
{
	int		i;
	int		count;

	if ((*list == '\0' || list == NULL) && (str != NULL && *str != '\0'))
		return (str);
	if (str)
	{
		while (*str)
		{
			i = -1;
			count = 0;
			while (list[++i])
				count += list[i] == *str;
			if (count == 0)
				return (str);
			str++;
		}
	}
	return (NULL);
}
