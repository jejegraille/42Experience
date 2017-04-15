/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 11:33:24 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/01 14:04:28 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int		check_only(t_lfd fi, t_ls ls)
{
	if (fi.stype == 'c' && ls.c > 1)
		return (1);
	if (fi.stype == 'o' && ls.o > 1)
		return (1);
	if (fi.type == 'd' && ls.d > 1)
		return (1);
	if (fi.type == 's' && ls.s > 1)
		return (1);
	if ((fi.name)[0] == '.' && ls.a > 1)
		return (1);
	if (fi.type == 'f' && ls.f > 1)
		return (1);
	if (fi.stype == 'i' && ls.i > 1)
		return (1);
	if (fi.stype == 'm' && ls.m > 1)
		return (1);
	if (ls.e > 1 && fi.type != 'd' && is_exe(fi.chmod, '-'))
		return (1);
	return (0);
}

int				vald(t_lfd file, t_ls ls)
{
	if (!(ls.a) && (file.name)[0] == '.')
		return (0);
	if (ls.rec && file.type == 'd')
	{
		if ((ft_strcmp(file.name, ".")) && (ft_strcmp(file.name, "..")))
			return (1);
	}
	return (0);
}

int				valf(t_lfd file, t_ls ls)
{
	if (ls.out > 0 && (!(ft_strcmp(file.name, ".")) ||
	!(ft_strcmp(file.name, ".."))))
		return (0);
	if (ls.first == 1 && file.type == 'd')
		return (0);
	if (!(ls.a) && (file.name)[0] == '.')
		return (0);
	if (ls.only)
		return (check_only(file, ls));
	return (1);
}
