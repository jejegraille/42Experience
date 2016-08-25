/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 22:48:56 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/11 00:49:24 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		nb2;
	long	nb3;

	nb3 = nb;
	nb2 = nb;
	if (power > 0)
	{
		while (power-- > 1)
		{
			nb3 = nb3 * nb2;
		}
	}
	else
	{
		return (power == 0 ? 1 : 0);
	}
	if (nb3 > 2147483647 || nb3 < -2147483648)
	{
		return (0);
	}
	else
	{
		return (nb3);
	}
}
