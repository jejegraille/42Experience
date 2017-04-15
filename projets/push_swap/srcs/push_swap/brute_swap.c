/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:05:32 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/09 13:47:28 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <unistd.h>

static void			sel_act(char **act, char **bact)
{
	int		rand;

	*act = "0123456789a";
	*bact = "012678345a9";
	rand = ft_rand() * 2;
	if (rand == 0)
	{
		*act = "3450126789a";
		*bact = "678012345a9";
	}
	else if (rand == 1)
	{
		*act = "9a543861207";
		*bact = "a9876531204";
	}
}

static char			*ps_algo(t_ps ps, char *comb, int i, char l_act)
{
	char	*act;
	char	*back_act;
	char	*res;
	int		i2;

	sel_act(&act, &back_act);
	res = NULL;
	if (check_order(*(ps.a), *(ps.b)))
		return (comb);
	else if (i < ps.max)
	{
		i2 = -1;
		while (act[++i2] && res == NULL)
		{
			if (check_pertnt(ps, act[i2], l_act, i) == 0)
				continue;
			ps_exec(&ps, act[i2]);
			comb[i] = act[i2];
			res = ps_algo(ps, comb, i + 1, act[i2]);
			ps_exec(&ps, back_act[i2]);
			if (res == NULL)
				comb[i] = '\0';
		}
	}
	return (res);
}

char				*brute_swap(t_lst **a, t_lst **b, int la)
{
	t_ps	ps;
	char	*comb;
	char	*res;

	ps = (t_ps){a, b, la, 0, 0, 0, 0};
	res = NULL;
	while (res == NULL)
	{
		comb = ft_strnew(ps.max);
		res = ps_algo(ps, comb, 0, '\0');
		if (res == NULL)
		{
			ft_memdel((void **)&comb);
			ps.max += 1;
		}
	}
	return (res);
}
