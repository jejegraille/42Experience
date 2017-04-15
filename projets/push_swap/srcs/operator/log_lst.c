/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 14:54:22 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 19:11:03 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>
#include <libft.h>

void	log_lst(t_lst *a, t_lst *b)
{
	char *tmp;

	ft_log("[PILE A]\n", NULL);
	while (a != NULL)
	{
		tmp = ft_itoa(a->nb);
		ft_log(tmp, " | ");
		ft_memdel((void **)&tmp);
		a = a->next;
	}
	ft_log("\n", NULL);
	ft_log("[PILE B]\n", NULL);
	while (b != NULL)
	{
		tmp = ft_itoa(b->nb);
		ft_log(tmp, " | ");
		ft_memdel((void **)&tmp);
		b = b->next;
	}
	ft_log("\n", NULL);
}
