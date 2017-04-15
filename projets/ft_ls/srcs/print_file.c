/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:40:01 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/01 13:04:58 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <ft_printf.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

static char			*print_color(t_lfd fi)
{
	char *color;

	color = "";
	if (fi.type == 'd')
		color = "\x1B[34m";
	if (fi.type == 'l')
		color = "\x1B[36m";
	if (fi.type == 'f')
		color = "\x1B[33m";
	if (fi.type == 's' || fi.stype == 'm' || fi.stype == 'i')
		color = "\x1B[35m";
	if (fi.stype == 'a')
		color = "\x1B[32m";
	if (fi.type != 'd' && is_exe(fi.chmod, 'u'))
		color = "\x1B[31m";
	return (color);
}

static void			print_mark(t_lfd fi, t_ls ls)
{
	char mark;

	mark = '0';
	if (ls.d && fi.type == 'd')
		mark = '/';
	if (ls.s && fi.type == 's')
		mark = '=';
	if (ls.f && fi.type == 'f')
		mark = '|';
	if (ls.e && fi.type != 'd' && is_exe(fi.chmod, '-'))
		mark = '*';
	if (mark != '0')
		ft_putchar(mark);
}

int					print_filed(t_lfd fi, t_ls ls, t_align al)
{
	if (ls.path)
	{
		if (ls.color)
			ft_putstr(print_color(fi));
		ft_putstr(fi.path);
		if (ls.color)
			ft_putstr("\x1B[0m");
		ft_putchar('\n');
		return (0);
	}
	if (ls.l)
		print_info(fi, al);
	if (ls.color)
		ft_putstr(print_color(fi));
	ft_printf("%s", fi.name);
	if (ls.color)
		ft_putstr("\x1B[0m");
	print_mark(fi, ls);
	if (ls.l && fi.type == 'l')
		ft_printf(" -> %s", fi.lname);
	ft_putchar('\n');
	return (0);
}
