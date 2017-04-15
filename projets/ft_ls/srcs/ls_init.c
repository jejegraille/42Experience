/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 11:22:42 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/04 20:10:32 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <ft_printf.h>
#include <unistd.h>

static int			onlyprint(t_ls *ls)
{
	if (ls->a > 1 || ls->d > 1 || ls->e > 1 || ls->f > 1)
		return (1);
	if (ls->s > 1 || ls->c > 1 || ls->i > 1 || ls->m > 1)
		return (1);
	if (ls->o > 1)
		return (1);
	return (0);
}

void				init_arg(t_ls *ls)
{
	ls->first = 1;
	ls->a = 0;
	ls->r = 0;
	ls->l = 0;
	ls->rec = 0;
	ls->t = 0;
	ls->d = 0;
	ls->e = 0;
	ls->f = 0;
	ls->s = 0;
	ls->c = 0;
	ls->o = 0;
	ls->i = 0;
	ls->m = 0;
	ls->out = 0;
	ls->count = 0;
	ls->color = 0;
	ls->path = 0;
	ls->only = 0;
	ls->ok = 0;
}

static void			next_part(t_ls *ls, char c)
{
	ls->i += c == 'i' ? 1 : 0;
	ls->m += c == 'm' ? 1 : 0;
	ls->o += c == 'o' ? 1 : 0;
	ls->path += c == 'P' ? 1 : 0;
	ls->count += c == 'C' ? 1 : 0;
}

int					init(t_ls *ls, char *arg)
{
	if (ft_stronly(arg, ls->legal))
		return (0);
	if (arg != NULL)
		while (*arg)
		{
			ls->a += *arg == 'a' ? 1 : 0;
			ls->r += *arg == 'r' ? 1 : 0;
			ls->l += *arg == 'l' ? 1 : 0;
			ls->rec += *arg == 'R' ? 1 : 0;
			ls->t += *arg == 't' ? 1 : 0;
			ls->d += *arg == 'd' ? 1 : 0;
			ls->e += *arg == 'e' ? 1 : 0;
			ls->f += *arg == 'f' ? 1 : 0;
			ls->s += *arg == 's' ? 1 : 0;
			ls->c += *arg == 'c' ? 1 : 0;
			ls->color += *arg == 'G' ? 1 : 0;
			ls->out += *arg == '-' ? 1 : 0;
			next_part(ls, *arg);
			arg++;
		}
	ls->only = onlyprint(ls);
	return (1);
}

int					arg(t_ls *ls, char *arg)
{
	if (ft_strcmp(arg, "-help") == 0)
	{
		ft_putstr("\x1B[44m");
		ft_putstr(ft_filetostr("./srcs/help"));
		ft_putstr("\x1B[0m");
		return (0);
	}
	if (init(ls, (arg + 1)) == 0)
	{
		ft_putstr_fd("ft_ls : illegal option -- ", 2);
		ft_putchar_fd(ft_stronly(arg, ls->legal)[0], 2);
		ft_putstr_fd("\nusage: ./ft_ls [-help] [-", 2);
		ft_putstr_fd(ls->legal, 2);
		ft_putstr_fd("] [file ...]\n", 2);
		return (0);
	}
	return (1);
}
