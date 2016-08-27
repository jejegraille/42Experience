/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 00:42:43 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/19 08:34:34 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int i;
	int i2;

	i = -1;
	while (tab[++i])
	{
		i2 = 0;
		while (tab[i][i2] != '\0')
		{
			ft_putchar(tab[i][i2]);
			i2++;
		}
		ft_putchar('\n');
	}
}
