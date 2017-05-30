/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:19:44 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/18 19:56:00 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		is_space(char c)
{
	return ((c == ' ' || c == '\t' || c == 0));
}

char	*ft_delwords(char *str, int nb)
{
	int count;
	int start;
	int	i;

	if (str == NULL || nb <= 0)
		return (str);
	count = 0;
	start = 0;
	i = -1;
	while (str[++i] && count - 1 < nb)
	{
		if (!is_space(str[i]) && (i == 0 || is_space(str[i - 1])))
			count++;
		if (count - 1 < nb)
			start++;
	}
	return (ft_strdup(str + start));
}
