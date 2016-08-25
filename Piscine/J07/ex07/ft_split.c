/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 06:27:54 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/20 06:28:26 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c, char *separator)
{
	int		yes;
	int		i;

	yes = 0;
	i = 0;
	while (separator[i])
	{
		if (separator[i] && c == separator[i])
			yes += 1;
		i++;
	}
	return (yes > 0 ? 1 : 0);
}

char	**format_tab(char *str, char *charset)
{
	char	**tab;
	int		word_count;
	int		i;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && !(is_separator(str[i], charset)))
			i++;
		word_count += (i > 0 ? 1 : 0);
		while (str[i] && is_separator(str[i], charset))
			i++;
	}
	tab = malloc(sizeof(*tab) * (word_count + 1));
	tab[word_count] = 0;
	return (tab);
}

char	*strcopy(char *src, int count, char *charset)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (count + 1));
	while (src[i] && !(is_separator(src[i], charset)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;
	char	*tmp_str;
	int		i2;
	int		count;

	tab = format_tab(str, charset);
	i = 0;
	i2 = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] && is_separator(str[i], charset))
			i++;
		while (str[i] != '\0' && !(is_separator(str[i], charset)))
		{
			tmp_str = (count == 0) ? str + i : tmp_str;
			i++;
			count++;
		}
		if (!(is_separator(str[i - 1], charset)))
			tab[i2++] = strcopy(tmp_str, count, charset);
	}
	return (tab);
}
