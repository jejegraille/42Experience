/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:41:01 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/15 06:34:41 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int n, char *base)
{
	ft_putchar(base[n]);
}

int		ft_check_error(int nbr, char *base)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_n[2];
	int	n;
	int	one;

	base_n[0] = 0;
	base_n[1] = 1;
	if (nbr < 0)
		ft_putchar('-');
	nbr = nbr * ((nbr < 0) ? -1 : 1);
	if (ft_check_error(nbr, base) == 0)
	{
		while (base[base_n[0]] != '\0')
			base_n[0]++;
		while (base_n[1] <= nbr)
			base_n[1] = base_n[1] * base_n[0];
		while (base_n[1] != 1 || one != 0)
		{
			base_n[1] = base_n[1] / base_n[0];
			base_n[1] = (base_n[1] < 1 ? 1 : base_n[1]);
			n = nbr / base_n[1];
			print(n, base);
			nbr = nbr - n * base_n[1];
			one = 0;
		}
	}
}
