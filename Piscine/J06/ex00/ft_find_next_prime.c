/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:07:31 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/11 01:22:25 by jgraille         ###   ########.fr       */
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

int		ft_find_next_prime(int nb)
{
	int i;
	int limit;
	int cursor;
	int test;

	cursor = nb - 1;
	test = 0;
	if (cursor > 2)
	{
		while (test == 0)
		{
			cursor++;
			test = 1;
			i = 2;
			limit = ft_sqrt(cursor);
			while (test != 0 && i < limit)
			{
				test = cursor % i;
				i++;
			}
		}
		return (cursor);
	}
	else
		return (2);
}
