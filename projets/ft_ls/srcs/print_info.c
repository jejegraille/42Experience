/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:59:15 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/04 16:33:34 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <ft_printf.h>
#include <time.h>
#include <unistd.h>

static void			print_time(long nsec)
{
	char	*tmp;
	time_t	ltime;
	time_t	stime;
	int		ecart;

	stime = (time_t)(nsec);
	tmp = ctime(&stime);
	time(&ltime);
	write(1, tmp + 4, 7);
	ecart = 365 * 12 * 3600;
	if (ltime - stime >= ecart || stime - ltime <= -ecart)
		write(1, tmp + 19, 5);
	else
		write(1, tmp + 11, 5);
	write(1, " ", 1);
}

static void			print_mod(mode_t mode)
{
	char	*droit;
	int		c;

	droit = ft_strnew(10);
	c = mode % 8;
	droit[6] = (c == 0 || c == 1 || c == 2 || c == 3) ? '-' : 'r';
	droit[7] = (c == 0 || c == 1 || c == 4 || c == 5) ? '-' : 'w';
	droit[8] = (c == 0 || c == 2 || c == 4 || c == 6) ? '-' : 'x';
	c = (mode / 8) % 8;
	droit[3] = (c == 0 || c == 1 || c == 2 || c == 3) ? '-' : 'r';
	droit[4] = (c == 0 || c == 1 || c == 4 || c == 5) ? '-' : 'w';
	droit[5] = (c == 0 || c == 2 || c == 4 || c == 6) ? '-' : 'x';
	c = (mode / (8 * 8)) % 8;
	droit[0] = (c == 0 || c == 1 || c == 2 || c == 3) ? '-' : 'r';
	droit[1] = (c == 0 || c == 1 || c == 4 || c == 5) ? '-' : 'w';
	droit[2] = (c == 0 || c == 2 || c == 4 || c == 6) ? '-' : 'x';
	ft_putstr(droit);
	ft_memdel((void **)&droit);
}

int					print_info(t_lfd fi, t_align al)
{
	ft_putchar(fi.type);
	print_mod(fi.chmod);
	ft_putchar(fi.attr && 0 ? '@' : ' ');
	ft_printf(" %*d ", al.link, fi.link);
	ft_printf("%-*s  %-*s  ", al.usr, fi.usr, al.grp, fi.grp);
	if (ft_strchr("bc", fi.type))
		ft_printf("%3d,%4d ", major(fi.dev), minor(fi.dev));
	else
		ft_printf("%*d ", al.size, fi.size);
	print_time(fi.time);
	return (0);
}
