/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pertnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:14:28 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/08 18:52:20 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			check_pertnt(t_ps ps, char act, char l_act, int i)
{
	if ((act == '0' || act == '1' || act == '2') && act == l_act)
		return (0);
	if ((act == '3' && l_act == '6') || (l_act == '3' && act == '6'))
		return (0);
	if ((act == '4' && l_act == '7') || (l_act == '4' && act == '7'))
		return (0);
	if ((act == '5' && l_act == '8') || (l_act == '5' && act == '8'))
		return (0);
	if (act == 'a' && ps.max - i < 3)
		return (0);
	if (ps.la == 0 && ft_strchr("023568a", act))
		return (0);
	if (ps.lb == 0 && ft_strchr("1245789", act))
		return (0);
	if (ps.max - i == ps.lb && act != '9')
		return (0);
	if (ps.max - i < ps.lb && ft_strchr("023568a", act))
		return (0);
	return (1);
}
