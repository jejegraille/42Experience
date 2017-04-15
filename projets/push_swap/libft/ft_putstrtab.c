/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:43:27 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/23 10:46:22 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab(char **tab, char separator)
{
	while (*tab)
	{
		ft_putstr(*tab);
		ft_putchar(separator);
		tab++;
	}
}
