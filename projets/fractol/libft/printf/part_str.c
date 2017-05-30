/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:36:31 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 12:16:13 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdarg.h>

char		*part_str(t_fmtid id, va_list *ap)
{
	char *str;

	str = va_arg(*ap, char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	str = cut_str(str, id);
	str = fill_str(str, id);
	return (str);
}
