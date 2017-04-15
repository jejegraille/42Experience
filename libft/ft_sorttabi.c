/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttabi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:51:16 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/08 18:22:47 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void			self_swp(int *tab, int i, int dec)
{
	int	tmp;

	(void)dec;
	tmp = tab[i];
	tab[i] = tab[0];
	tab[0] = tmp;
}

void				ft_sorttabi(int *tab, int len, int dec)
{
	int min;
	int	imin;
	int	i;
	int	i2;

	i = -1;
	while (++i < len - 1)
	{
		imin = 0;
		min = tab[0];
		i2 = -1;
		while (++i2 < len - i)
		{
			if (min > tab[i2])
			{
				min = tab[i2];
				imin = i2;
			}
		}
		self_swp(tab, imin, dec);
		tab++;
	}
}
