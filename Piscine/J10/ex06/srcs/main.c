/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 14:10:10 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/20 18:04:02 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_proto.h"

int		check_in(char o, char *list)
{
	int		i;
	int		ok;

	ok = 0;
	i = -1;
	while (list[++i])
		ok += (o == list[i]);
	return (ok);
}

int		check_error(char **av)
{
	int i;
	int error;

	error = 0;
	i = 0;
	while (av[2][i])
		i++;
	error += (i == 1) ? 0 : 1;
	if (i == 1)
		error += (check_in(av[2][0], "+-*/%") == 1) ? 0 : 1;
	return (error > 0 ? 1 : 0);
}

void	message(char c)
{
	if (c == '/')
		ft_putstr("Stop : division by zero\n");
	else
		ft_putstr("Stop : modulo by zero\n");
}

int		main(int ac, char **av)
{
	int resultat;
	int a;
	int b;
	int stop;

	resultat = 0;
	stop = 0;
	if (ac == 4)
	{
		if (check_error(av) == 0)
		{
			a = ft_atoi(av[1]);
			b = ft_atoi(av[3]);
			if (b == 0 && (av[2][0] == '%' || av[2][0] == '/'))
			{
				message(av[2][0]);
				stop = 1;
			}
			else
				resultat = operation(a, b, av[2][0]);
		}
		if (stop == 0)
			ft_putnbr(resultat);
	}
	return (0);
}
