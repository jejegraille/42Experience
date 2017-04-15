/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_cap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:17:08 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/22 14:54:24 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			fts_cap(char *cap)
{
	char *tcap;

	if ((tcap = tgetstr(cap, NULL)) == NULL)
		return (-1);
	ft_putstr_fd(tcap, g_fts.fd);
	return (0);
}

int			fts_cap_write(char *str, int x, int y)
{
	int		i;
	int		len;

	i = -1;
	while (++i < y)
		fts_cap("do");
	i = -1;
	while (++i < x)
		fts_cap("nd");
	ft_putstr_fd(str, g_fts.fd);
	i = -1;
	len = (int)ft_strlen(str);
	while (++i < (x + len))
		fts_cap("le");
	i = -1;
	while (++i < y)
		fts_cap("up");
	return (0);
}
