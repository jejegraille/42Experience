/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 07:59:42 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/07 19:30:22 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		nbr_at(long a, long d)
{
	d = d == 0 ? 1 : d;
	return ((a % (d * 10)) / d);
}

void	ft_putnbr(int nb)
{
	long	dixaine;
	long	nb2;
	char	neg;
	int		one;

	nb2 = nb;
	neg = (nb2 < 0) ? '-' : 0;
	nb2 = nb2 < 0 ? nb2 * -1 : nb2;
	dixaine = 1;
	while (dixaine < nb2)
	{
		dixaine = dixaine * 10;
	}
	dixaine = dixaine / 10;
	one = 0;
	ft_putchar(neg);
	while (dixaine > 0 || one == 0)
	{
		one = 1;
		ft_putchar('0' + nbr_at(nb2, dixaine));
		dixaine = dixaine / 10;
	}
}
