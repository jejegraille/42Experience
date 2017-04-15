/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:43:00 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/04 20:53:51 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static char		*format(long nbr, unsigned long long *grand)
{
	size_t	len;

	len = nbr >= 0 ? 1 : 2;
	nbr = nbr >= 0 ? nbr : -nbr;
	*grand = 10;
	while (*grand <= (unsigned long long)nbr)
	{
		*grand *= 10;
		len++;
	}
	return (ft_strnew(len));
}

char			*ft_ltoa(long n)
{
	int					is_neg;
	char				*nbr;
	unsigned long long	grand;
	size_t				len;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	nbr = format(n, &grand);
	if (nbr == NULL)
		return (NULL);
	is_neg = n < 0 ? 1 : 0;
	n *= n > 0 ? 1 : -1;
	len = 0;
	while (grand > 1)
	{
		grand = grand / 10 == 0 ? 1 : grand / 10;
		nbr[is_neg + len++] = '0' + (n / grand);
		n = n % grand;
	}
	nbr[0] = is_neg ? '-' : nbr[0];
	return (nbr);
}
