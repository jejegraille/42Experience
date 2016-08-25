/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 02:48:11 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/12 09:44:15 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*normalise(char *tab)
{
	int i;
	int zap;

	i = 0;
	zap = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == ' ' || tab[i] == '	')
			zap += 1;
		else if (65 <= tab[i] && tab[i] <= 90)
			tab[i] = tab[i] + 32;
		i++;
	}
	return (tab + zap);
}

int		check_arg(char *tab1, char *tab2)
{
	int i;

	i = 0;
	tab1 = normalise(tab1);
	while (tab1[i] == tab2[i])
	{
		i++;
		if (tab2[i] == '\0')
			return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*tab[3];
	int		compar;

	if (argc > 0)
	{
		tab[0] = "president";
		tab[1] = "attack";
		tab[2] = "powers";
		compar = 2;
		i = 0;
		while (argc-- > 0)
		{
			while (compar >= 0)
			{
				if (check_arg(argv[argc], tab[compar]) == 1)
					write(1, "Alert!!!\n", 8);
				if (check_arg(argv[argc], tab[compar]) == 1)
					return (0);
				compar--;
			}
			compar = 2;
		}
	}
	return (0);
}
