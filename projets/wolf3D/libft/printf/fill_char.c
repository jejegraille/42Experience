/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:40:51 by aroulin           #+#    #+#             */
/*   Updated: 2017/05/27 12:12:30 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char	fill_char(char *str, t_fmtid id)
{
	id.sign = 0;
	if (str[0] == '-')
		id.sign = '-';
	else if (id.flag && ft_strchr(id.flag, '+'))
		id.sign = '+';
	else if (id.flag && ft_strchr(id.flag, ' '))
		id.sign = ' ';
	return (id.sign);
}
