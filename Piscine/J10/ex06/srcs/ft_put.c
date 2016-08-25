/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 07:59:42 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/24 01:20:39 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		nbr_at(long a, long d)
{
	d = d <= 1 ? 1 : d;
	return ((a % (d * 10)) / d);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putnbr(int nb)
{
	long	dixaine;
	long	nb2;
	int		one;

	nb2 = nb;
	if (nb2 < 0)
		ft_putchar('-');
	nb2 = nb2 < 0 ? nb2 * -1 : nb2;
	dixaine = 1;
	while (dixaine <= nb2)
	{
		dixaine = dixaine * 10;
	}
	dixaine = dixaine / 10;
	one = 0;
	while (dixaine >= 1 || one == 0)
	{
		one = 1;
		ft_putchar('0' + nbr_at(nb2, dixaine));
		dixaine = dixaine / 10;
	}
	ft_putchar('\n');
}
