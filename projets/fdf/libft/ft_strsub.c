/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:47:41 by jgraille          #+#    #+#             */
/*   Updated: 2016/12/09 18:11:01 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*freshstr;
	size_t	i;

	freshstr = (char *)malloc(len + 1);
	if (freshstr != NULL)
	{
		i = 0;
		while (i < len)
		{
			freshstr[i] = s[i + start];
			i++;
		}
		freshstr[i] = '\0';
	}
	return (freshstr);
}
