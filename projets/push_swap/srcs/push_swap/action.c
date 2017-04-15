/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:55:14 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/12 11:45:00 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char				*str_act(char c)
{
	char *act;

	act = NULL;
	(c == '0') && (act = "sa");
	(c == '1') && (act = "sb");
	(c == '2') && (act = "ss");
	(c == '3') && (act = "ra");
	(c == '4') && (act = "rb");
	(c == '5') && (act = "rr");
	(c == '6') && (act = "rra");
	(c == '7') && (act = "rrb");
	(c == '8') && (act = "rrr");
	(c == '9') && (act = "pa");
	(c == 'a') && (act = "pb");
	(c == 'b') && (act = "nimpb");
	return (act);
}

void				ps_exec(t_ps *ps, char act)
{
	t_fct fct;

	(act == '0') && (fct = &sa);
	(act == '1') && (fct = &sb);
	(act == '2') && (fct = &ss);
	(act == '3') && (fct = &ra);
	(act == '4') && (fct = &rb);
	(act == '5') && (fct = &rr);
	(act == '6') && (fct = &rra);
	(act == '7') && (fct = &rrb);
	(act == '8') && (fct = &rrr);
	(act == 'b') && (fct = &sb);
	if ((act == '9') && (fct = &pa))
	{
		ps->la += 1;
		ps->lb -= 1;
	}
	if ((act == 'a') && (fct = &pb))
	{
		ps->la -= 1;
		ps->lb += 1;
	}
	fct(ps->a, ps->b);
}
