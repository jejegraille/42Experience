/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 04:16:05 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/21 08:23:14 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_intostr(int nb)
{
	long	i;
	long	nb2;
	long	grand;
	char	*str;

	nb2 = nb;
	grand = 1;
	i = (nb2 < 0);
	nb2 = (nb2 < 0) ? -nb2 : nb2;
	while (grand <= nb2)
	{
		grand = grand * 10;
		i++;
	}
	i = (i == 0) ? 1 : i;
	str = malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	str[0] = '-';
	while (nb2 >= 0)
	{
		str[i] = (nb2 % 10) + '0';
		nb2 = (nb2 < 10) ? -1 : nb2 / 10;
		i--;
	}
	return (str);
}
