/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 08:12:38 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/23 01:53:54 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c)
{
	int		yes;
	char	*separator;
	int		i;

	separator = "	\n ";
	yes = 0;
	i = 0;
	while (separator[i])
	{
		if (separator[i] && c == separator[i])
			yes += 1;
		i++;
	}
	return (yes);
}

char	**format_tab(char *str)
{
	char	**tab;
	int		word_count;
	int		i;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && !(is_separator(str[i])))
			i++;
		word_count += (i > 0 ? 1 : 0);
		while (str[i] && is_separator(str[i]))
			i++;
	}
	tab = malloc(sizeof(*tab) * (word_count + 1));
	tab[word_count] = 0;
	return (tab);
}

char	*strcopy(char *src, int count)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (count + 1));
	while (src[i] && !(is_separator(src[i])))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	char	**tab;
	char	*tmp_str;
	int		i2;
	int		count;

	tab = format_tab(str);
	i = 0;
	i2 = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] && is_separator(str[i]))
			i++;
		while (str[i] != '\0' && !(is_separator(str[i])))
		{
			tmp_str = (count == 0) ? str + i : tmp_str;
			i++;
			count++;
		}
		if (!(is_separator(str[i - 1])))
			tab[i2++] = strcopy(tmp_str, count);
	}
	return (tab);
}
