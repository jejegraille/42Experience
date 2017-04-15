/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:34:06 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/14 15:53:10 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		sp_count(char const *s, char *c)
{
	int	count;
	int i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && ft_strchr(c, s[i]) && (i != 0 && !ft_strchr(c, s[i - 1])))
			count++;
		i++;
	}
	if (s[i] == 0 && !ft_strchr(c, s[i - 1]))
		count++;
	return (count);
}

static void		writetable(char const *s, char **table, char *c)
{
	int countwords;
	int len;
	int i;

	len = 0;
	i = 0;
	countwords = 0;
	while (s[i])
	{
		if (!ft_strchr(c, s[i]))
			len++;
		if (ft_strchr(c, s[i]) && (i != 0 && !ft_strchr(c, s[i - 1])))
		{
			table[countwords++] = ft_strsub(s + i - len, 0, len);
			len = 0;
		}
		i++;
	}
	if (s[i] == 0 && !ft_strchr(c, s[i - 1]))
		table[countwords++] = ft_strsub(s + i - len, 0, len);
	table[countwords] = 0;
}

char			**ft_split_c(char const *s, char *c)
{
	char	**table;

	if (s != NULL && *s != 0)
	{
		table = (char **)malloc(sizeof(char *) * (sp_count(s, c) + 1));
		if (table == NULL)
			return (NULL);
		writetable(s, table, c);
	}
	else
	{
		table = (char **)malloc(sizeof(char*));
		table[0] = NULL;
	}
	return (table);
}
