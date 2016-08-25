/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 22:21:17 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/23 02:29:24 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_par.h"

void	print_str(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	ft_putchar('\n');
}

int		nbr_at(long a, long d)
{
	d = d <= 1 ? 1 : d;
	return ((a % (d * 10)) / d);
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
		dixaine = dixaine * 10;
	dixaine = dixaine / 10;
	one = 0;
	while (dixaine >= 1 || one == 0)
	{
		one = 1;
		ft_putchar('0' + nbr_at(nb2, dixaine));
		dixaine = dixaine / 10;
	}
}

void	print_table(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		print_str(tab[i]);
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;

	i = -1;
	while (par[++i].str)
	{
		print_str(par[i].str);
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		print_table(par[i].tab);
	}
}
