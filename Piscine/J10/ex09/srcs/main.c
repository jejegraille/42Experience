/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 07:04:12 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/24 01:24:39 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_proto.h"
#include "../includes/ft_struct.h"
#include "../includes/ft_opp.h"

void	ft_usage(int a, int b)
{
	int i;

	a = b;
	ft_putstr("error : only [ ");
	i = -1;
	while (++i < 5)
	{
		ft_putstr(g_opptab[i].operateur);
		ft_putchar(' ');
	}
	ft_putstr("] are accepted.\n");
}

void	param_oper(char *opr, void (**f)(int, int))
{
	int		i;
	int		i2;
	int		stop;

	i = -1;
	stop = 0;
	while (stop == 0 && ++i < 5)
	{
		i2 = 0;
		while (opr[i2] && opr[i2] == g_opptab[i].operateur[i2])
			i2++;
		if (g_opptab[i].operateur[i2] == '\0')
		{
			*f = g_opptab[i].fonction;
			stop = 1;
		}
	}
	if (stop == 0)
		*f = g_opptab[5].fonction;
}

int		main(int ac, char **av)
{
	int		a;
	int		b;
	void	(*operation)(int, int);

	operation = 0;
	if (ac == 4)
	{
		a = ft_atoi(av[1]);
		b = ft_atoi(av[3]);
		param_oper(av[2], &operation);
		operation(a, b);
	}
	return (0);
}
