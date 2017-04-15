/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:06:44 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/12 11:22:04 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <unistd.h>

static char			conv_act(t_clst **lc)
{
	t_clst	*tmp;
	char	c;
	char	act;
	char	c2;

	c = (*lc)->c;
	act = c;
	c2 = (*lc)->next ? (*lc)->next->c : '\0';
	tmp = *lc;
	*lc = (*lc)->next;
	ft_memdel((void **)&tmp);
	(c == act && c == '0' && c2 == '1' && (act = '2'));
	(c == act && c == '1' && c2 == '0' && (act = '2'));
	(c == act && c == '3' && c2 == '4' && (act = '5'));
	(c == act && c == '4' && c2 == '3' && (act = '5'));
	(c == act && c == '6' && c2 == '7' && (act = '8'));
	(c == act && c == '7' && c2 == '6' && (act = '8'));
	if (c != act)
	{
		tmp = *lc;
		*lc = (*lc)->next;
		ft_memdel((void **)&tmp);
	}
	return (act);
}

static char 		*conv_clst(t_clst *l, int count)
{
	char	*res;
	int		i;

	if (count == 0)
		return (NULL);
	res = ft_strnew(count);
	i = 0;
	while (l != NULL)
		res[i++] = conv_act(&l);
	return (res);
}

static void			simplify_lst(t_lst *a, int count)
{
	int		tb[count];
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = a;
	while(tmp != NULL)
	{
		tb[i++] = tmp->nb;
		tmp = tmp->next;
	}
	ft_sorttabi(tb, count, 0);
	i = 0;
	while(a != NULL)
	{
		i = 0;
		while(tb[i] != a->nb)
			i++;
		a->nb = i;
		a = a->next;
	}
}

char				*mind_swap(t_lst **a, t_lst **b, int la)
{
	t_ps	ps;
	char	*c;
	char	*tmp;
	int		count;
	int		count2;
	t_clst	*cl;

	ps = (t_ps){a, b, la, 0, la - 1, 0, 0};
	count = 0;
	count2 = -1;
	cl = NULL;
	simplify_lst(*a, la);
	while (check_order(*a, *b) == 0)
	{
		c = ps_search_act(&ps);
		tmp = c;
		while (*c)
		{
			ps_exec(&ps, *c);
			add_clst(&cl, *c);
			count++;
			c++;
		}
		ft_memdel((void **)&tmp);
	}
	return (conv_clst(cl, count));
}
