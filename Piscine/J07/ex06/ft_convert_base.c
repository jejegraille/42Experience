/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 01:53:26 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/17 10:00:34 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*convert_int_to_base(char *str, int nb, char *base)
{
	int		base_x;
	int		number;
	int		i;

	base_x = 0;
	while (base[base_x] != '\0')
		base_x++;
	i = 0;
	while (nb > 0 || i == 0)
	{
		number = nb % base_x;
		str[i] = base[number];
		nb = nb / base_x;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		c_to_int(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != c && base[i] != '\0')
		i++;
	if (base[i] == '\0')
		return (0);
	return (i);
}

int		convert_base_to_int(char *nb, char *base)
{
	int		base_x[2];
	int		number;
	int		i;

	base_x[0] = 0;
	number = 0;
	while (base[base_x[0]] != '\0')
		base_x[0]++;
	i = 0;
	while (nb[i] != '\0')
		i++;
	base_x[1] = 1;
	while (--i >= 0)
	{
		number += c_to_int(nb[i], base) * base_x[1];
		base_x[1] = base_x[1] * base_x[0];
	}
	return (number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*str;
	char	tmp;
	int		i;
	int		i2;

	str = malloc(sizeof(char) * 32);
	nb = convert_base_to_int(nbr, base_from);
	convert_int_to_base(str, nb, base_to);
	i = 0;
	while (str[i] != '\0')
		i++;
	i2 = 0;
	while (i2 < --i)
	{
		tmp = str[i2];
		str[i2] = str[i];
		str[i] = tmp;
		i2++;
	}
	return (str);
}
