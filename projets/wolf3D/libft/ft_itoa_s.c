/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 12:23:50 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 15:06:47 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long nbr, long *grand)
{
	size_t	len;

	len = nbr >= 0 ? 1 : 2;
	nbr = nbr >= 0 ? nbr : -nbr;
	*grand = 10;
	while (*grand <= nbr)
	{
		*grand *= 10;
		len++;
	}
	return (len);
}

int				ft_itoa_s(char *str, int n)
{
	long	n2;
	int		is_neg;
	long	grand;
	size_t	i;
	size_t	nbr_len;

	n2 = n;
	nbr_len = get_len(n2, &grand);
	is_neg = n2 < 0 ? 1 : 0;
	n2 *= n2 > 0 ? 1 : -1;
	i = 0;
	while (grand > 1)
	{
		grand = grand / 10 == 0 ? 1 : grand / 10;
		str[is_neg + i++] = '0' + (n2 / grand);
		n2 = n2 % grand;
	}
	str[0] = is_neg ? '-' : str[0];
	return (nbr_len);
}
