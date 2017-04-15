/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:50:25 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/01 16:55:18 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void		check_doublon(t_lst *a, char **serror)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = a;
	while (*serror == NULL && tmp != NULL)
	{
		tmp2 = a;
		while (*serror == NULL && tmp2 != NULL)
		{
			if (tmp2 != tmp && tmp2->nb == tmp->nb)
				*serror = "Error : doublon";
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
