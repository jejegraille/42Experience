/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:41:01 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/18 08:09:12 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_check_error(char *base)
{
	int error;
	int i[2];

	error = 0;
	i[0] = 0;
	while (base[i[0]] != '\0')
	{
		i[1] = 0;
		while (base[i[1]] != '\0')
		{
			if (base[i[1]] == base[i[0]] && i[0] != i[1])
				error += 1;
			if (base[i[1]] == '-' || base[i[1]] == '+')
				error += 1;
			if (0 <= base[i[1]] && base[i[1]] <= 31)
				error += 1;
			i[1] += 1;
		}
		i[0]++;
		i[1] = 0;
	}
	if (i[0] <= 1)
		error += 1;
	return (error);
}

void	define(long *base_n, long *grandeur, char *base, long *nbr)
{
	*base_n = 0;
	*grandeur = 1;
	*nbr = *nbr * ((*nbr < 0) ? -1 : 1);
	while (base[*base_n] != '\0')
		*base_n = *base_n + 1;
	while (*grandeur <= *nbr)
		*grandeur *= *base_n;
	*grandeur = *grandeur / *base_n;
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	base_n;
	long	grandeur;
	int		n;
	long	nbr2;
	int		one;

	nbr2 = nbr;
	if (nbr2 < 0)
		ft_putchar('-');
	define(&base_n, &grandeur, base, &nbr2);
	if (ft_check_error(base) == 0)
	{
		while (grandeur >= 1 || one != 0)
		{
			n = (nbr2 / grandeur);
			ft_putchar(base[n]);
			nbr2 = nbr2 % grandeur;
			grandeur = grandeur / base_n;
			one = 0;
		}
	}
}
