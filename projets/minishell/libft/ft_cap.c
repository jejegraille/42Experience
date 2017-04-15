/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:09:19 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/22 18:19:08 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <term.h>
#include <curses.h>

int			ft_cap(char *cap, int fd)
{
	char *tcap;

	if ((tcap = tgetstr(cap, NULL)) == NULL)
		return (-1);
	ft_putstr_fd(tcap, fd);
	return (0);
}

int			ft_cap_write(char *str, int x, int y, int fd)
{
	int		i;
	int		len;

	i = -1;
	while (++i < y)
		ft_cap("do", fd);
	i = -1;
	while (++i < x)
		ft_cap("nd", fd);
	ft_putstr_fd(str, fd);
	i = -1;
	len = (int)ft_strlen(str);
	while (++i < (x + len))
		ft_cap("le", fd);
	i = -1;
	while (++i < y)
		ft_cap("up", fd);
	return (0);
}
