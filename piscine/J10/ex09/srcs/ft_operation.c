/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 15:07:50 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/23 07:03:19 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_proto.h"

void	ft_mod(int a, int b)
{
	int resultat;

	resultat = 0;
	if (b != 0)
	{
		resultat = (a % b);
		ft_putnbr(resultat);
	}
	else
		ft_putstr("Stop : modulo by zero");
	ft_putchar('\n');
}

void	ft_div(int a, int b)
{
	int resultat;

	resultat = 0;
	if (b != 0)
	{
		resultat = (a / b);
		ft_putnbr(resultat);
	}
	else
		ft_putstr("Stop : division by zero");
	ft_putchar('\n');
}

void	ft_sub(int a, int b)
{
	int resultat;

	resultat = (a - b);
	ft_putnbr(resultat);
	ft_putchar('\n');
}

void	ft_mul(int a, int b)
{
	int resultat;

	resultat = (a * b);
	ft_putnbr(resultat);
	ft_putchar('\n');
}

void	ft_add(int a, int b)
{
	int resultat;

	resultat = (a + b);
	ft_putnbr(resultat);
	ft_putchar('\n');
}
