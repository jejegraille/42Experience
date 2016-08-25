/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 20:52:24 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/23 02:01:54 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

struct	s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par	*par;
	int					i;
	int					i2;

	i = -1;
	par = malloc(sizeof(*par) * (ac + 1));
	while (++i < ac)
	{
		i2 = 0;
		while (av[i][i2])
			i2++;
		par[i].tab = ft_split_whitespaces(av[i]);
		par[i].str = av[i];
		par[i].copy = malloc(sizeof(char) * i2);
		i2 = -1;
		while (av[i][++i2])
			par[i].copy[i2] = av[i][i2];
		par[i].copy[i2] = '\0';
		par[i].size_param = i2;
	}
	par[i].str = 0;
	return (par);
}
