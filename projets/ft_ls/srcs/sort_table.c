/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:32:35 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/04 17:30:54 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>

static int			re(int value, char index, int rev)
{
	if (rev)
		return (index == 's' ? (value > 0) : (value < 0));
	else
		return (index == 's' ? (value < 0) : (value > 0));
}

static void			sort_ascii(t_lfd **tab, int len, int r)
{
	int		start;
	int		end;
	char	*piv;

	start = 0;
	end = len - 1;
	if (len > 1)
	{
		piv = tab[end]->name;
		while (start < end)
		{
			while (start < end && re(ft_strcmp(tab[start]->name, piv), 's', r))
				start++;
			while (end > start && re(ft_strcmp(tab[end]->name, piv), 'e', r))
				end--;
			swap_any((void **)&(tab[start]), (void **)&(tab[end]));
		}
		sort_ascii(tab, end, r);
		sort_ascii(tab + end + 1, len - end - 1, r);
	}
}

static void			second_sort(t_lfd **tab, int rev)
{
	int		start;
	int		end;

	start = -1;
	end = 0;
	while (tab[end + 1])
	{
		if (start == -1 && (tab[end]->time) == (tab[end + 1]->time))
			start = end;
		if (start != -1 && (tab[end]->time) != (tab[end + 1]->time))
		{
			sort_ascii(tab + start, end - start + 1, rev);
			start = -1;
		}
		end++;
	}
	if (start != -1)
		sort_ascii(tab + start, end - start + 1, rev);
}

static void			sort_time(t_lfd **tab, int len, int rev)
{
	int		i;

	i = 0;
	while (i + 1 < len)
	{
		if (re(tab[i]->time - tab[i + 1]->time, 's', rev))
		{
			swap_any((void **)&(tab[i]), (void **)&(tab[i + 1]));
			i -= i == 0 ? 0 : 1;
		}
		else
			i++;
	}
	second_sort(tab, rev);
}

void				sort_tab(t_lfd **tab, t_ls ls)
{
	if (ls.len > 1)
	{
		if (ls.t)
			sort_time(tab, ls.len, ls.r);
		else
			sort_ascii(tab, ls.len, ls.r);
	}
}
