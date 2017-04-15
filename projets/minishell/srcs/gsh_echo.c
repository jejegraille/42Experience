/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:46:30 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/25 15:09:10 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>

void	gsh_echo(t_gsh *data, char **tab)
{
	int	nl;

	tab++;
	nl = 1;
	if (tab[0] && ft_strcmp(tab[0], "-n") == 0 && (nl = 0))
		tab++;
	ft_putstrtab(tab, ' ');
	if (nl == 1)
		ft_putchar('\n');
	data->ok = 1;
}
