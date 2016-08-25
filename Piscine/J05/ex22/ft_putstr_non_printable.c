/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 08:16:20 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/18 08:46:46 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_hex(int nb)
{
	char	*base;
	int		grandeur;

	grandeur = 16;
	base = "0123456789abcdef";
	ft_putchar('\\');
	while (grandeur >= 1)
	{
		ft_putchar(base[nb / grandeur]);
		nb = nb % grandeur;
		grandeur = grandeur / 16;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 31)
			ft_putchar(str[i]);
		else
			print_hex(str[i]);
		i++;
	}
}
