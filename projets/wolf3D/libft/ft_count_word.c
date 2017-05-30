/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:16:10 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/11 15:16:46 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char const *s, const char *s2)
{
	int		count;
	size_t	i;
	size_t	len;
	size_t	len2;

	len = ft_strlen(s);
	len2 = ft_strlen(s2);
	count = 0;
	i = len2;
	while (i < len)
	{
		if (!ft_strncmp(s + i, s2, len2) && ft_strncmp(s + i - len2, s2, len2))
			count++;
		if (ft_strnequ(s + i, s2, len2))
			i = i + len2;
		else
			i++;
	}
	if (!ft_strnequ(s + len - len2, s2, len2))
		count++;
	return (count);
}
