/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:28:08 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/18 12:31:51 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <unistd.h>

int		put_format(char **format)
{
	size_t ind;

	ind = 0;
	while ((*format)[ind] && !ft_strchr("%{", (*format)[ind]))
		ind++;
	write(1, *format, ind);
	(*format) += ind;
	return (ind);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (!ft_strchr("%{", *format))
			count += put_format((char **)&format);
		else
			count += str_special(format_identifier((char **)&format), &ap);
	}
	va_end(ap);
	return (count);
}
