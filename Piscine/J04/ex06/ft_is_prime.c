/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 02:27:18 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/11 01:13:41 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;
	int n2;

	n2 = 0;
	i = 0;
	while (n2 < nb)
	{
		i++;
		n2 = i * i;
	}
	return (n2 == nb ? i : i - 1);
}

int		ft_is_prime(int nb)
{
	int i;
	int test;
	int nb_sqrt;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb == 3)
		return (1);
	if ((nb % 2) == 0)
		return (0);
	i = 3;
	nb_sqrt = ft_sqrt(nb);
	while ((test = (nb % i)) != 0 && i < nb_sqrt)
		i++;
	return (test == 0 ? 0 : 1);
}
