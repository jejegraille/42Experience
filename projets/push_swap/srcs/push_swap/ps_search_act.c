/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_search_act.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:12:29 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/15 11:41:53 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		chose_step(t_ps *ps)
{
	t_lst		*a;
	int			step;

	step = 0;
	a = *(ps->a);
	while (a->next != NULL && (a->nb < a->next->nb))
		a = a->next;
	if (a->next == NULL)
		step = 1;
	return (step);
}

static void		init_(t_lst **a, t_lst **b, char **act, t_ps *ps)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *(ps->a);
	while (tmp && tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	a[2] = i > 1 ? tmp : NULL;
	i = 0;
	tmp = *(ps->b);
	while (tmp && tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	b[2] = i > 1 ? tmp : NULL; 
	a[0] = *(ps->a);
	a[1] = a[0] != NULL ? (a[0])->next : NULL;
	b[0] = *(ps->b);
	b[1] = b[0] != NULL ? (b[0])->next : NULL;
	*act = ft_strnew(3);
}

static void		search_born(t_lst **a, t_born *born)
{
	int		min;
	int		max;

	min = (a[0])->nb;
	min = (a[1]) && (a[1])->nb < min ? (a[1])->nb : min;
	min = (a[2]) && (a[2])->nb < min ? (a[2])->nb : min;
	max = (a[0])->nb;
	max = (a[1]) && (a[1])->nb > max ? (a[1])->nb : max;
	max = (a[2]) && (a[2])->nb > max ? (a[2])->nb : max;
	born->min = min;
	born->max = max;
}

static char		*step_1(t_ps *ps)
{
	t_lst	*a[3];
	t_lst	*b[3];
	char	*act;
	int		i;
	t_born	born;

	init_(a, b, &act, ps);
	search_born(b, &born);
	i = 0;
	if  ((b[0]->nb) == born.max)
		act[i++] = '9';
	else
		act[i++] = (b[2] && (b[2])->nb == born.max) ? '7' : '1';
	return (act);
}

static char		*step_0(t_ps *ps)
{
	t_lst	*a[3];
	t_lst	*b[3];
	char	*act;
	int		i;
	t_born	born;

	init_(a, b, &act, ps);
	search_born(a, &born);
	i = 0;
	if ((a[0])->nb == born.max)
		act[i++] = '3';
	else if ((a[0])->nb == born.min)
	{
		act[i++] = 'a';
		if (b[0] && (a[0])->nb < (b[0])->nb)
		{
			if (b[1] && (a[0])->nb > (b[1])->nb)
				act[i++] = '1';
			else if (b[2] && (b[2])->nb < (a[0])->nb)
				act[i++] = '4';
			else if (b[2] && b[1] && (b[1])->nb > (a[0])->nb)
				act[i++] = '1';
		}
	}
	else
		act[i++] = '0';
	return (act);
}

static char		*step_2(t_ps *ps)
{
	t_lst	*a[3];
	t_lst	*b[3];
	char	*act;
	int		i;
	t_born	born;

	init_(a, b, &act, ps);
	search_born(a, &born);
	i = 0;
	if (a[2] && (a[0])->nb == born.max)
		act[i++] = '3';
	else if ((a[0])->nb == born.min)
	{
		act[i++] = 'a';
		if (b[0])
		{
			if (b[2] && (b[2])->nb < (a[0])->nb)
				act[i++] = '4';
			else if (b[2] && b[1] && (b[1])->nb > (a[0])->nb)
				act[i++] = '1';
		}
	}
	else
		act[i++] = '0';
	return (act);
}

char		*ps_search_act(t_ps *ps)
{
	static int	step;

	step = chose_step(ps);
	if (step == 0)
		return (step_0(ps));
	else if (step == 1)
		return (step_1(ps));
	else
		return (step_2(ps));
}
