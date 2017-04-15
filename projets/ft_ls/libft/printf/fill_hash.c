/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:51:51 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/18 12:29:51 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static char		*put_hash(char *hash, char *s, t_fmtid id)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*tmp;

	l = ft_strlen(s);
	i = 0;
	j = 0;
	while (s[i] == ' ')
		i++;
	while (s[i + j] == '0' && (long)(l - i - j) > id.lp && j < ft_strlen(hash))
		j++;
	if (s[i + j] == '0' && ft_strchr("oO", id.arg))
		return (s);
	if (i + j >= ft_strlen(hash) && !(ft_strchr(id.flag, '-')) && i + j != l)
		ft_memcpy(s + i + j - ft_strlen(hash), hash, ft_strlen(hash));
	else if (i + j != l)
	{
		tmp = ft_strjoin(hash, s + i + j);
		ft_memdel((void **)&s);
		s = tmp;
	}
	return (s);
}

char			*fill_hash(char *s, t_fmtid id)
{
	char	*hash;

	if (s == NULL || id.flag == NULL || !ft_strchr(id.flag, '#'))
		return (s);
	hash = ft_strchr("xX", id.arg) ? ft_strdup("0X") : ft_strdup("0");
	s = put_hash(hash, s, id);
	ft_memdel((void**)&hash);
	return (s);
}
