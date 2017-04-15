/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:16:33 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/01 16:36:51 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_pass(char c)
{
	if (c == 32 || c == 11 || c == 9 || c == '\r' || c == '\n' || c == '\f')
		return (1);
	return (0);
}

long		ft_atol(const char *str)
{
	int		signe;
	long	number;

	if (!*str)
		return (0);
	while (check_pass((unsigned char)(*str)))
		str++;
	signe = *(str) == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	number = 0;
	while (*str && ft_isdigit(*str))
	{
		number = number * 10 + (unsigned char)*str - '0';
		str++;
	}
	return ((long)(number * signe));
}
