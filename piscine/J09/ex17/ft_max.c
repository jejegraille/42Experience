/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 12:13:04 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/12 12:23:01 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, int length)
{
	int max;

	max = -2147483648;
	while (length > 0)
	{
		if (tab[length - 1] > max)
		{
			max = tab[length - 1];
		}
		length--;
	}
	return (max);
}
