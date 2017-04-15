/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 14:35:14 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/08 18:12:25 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;
	char	*serror;
	int		ret;

	ret = 0;
	if (ac == 1)
		return (1);
	serror = NULL;
	convert(&a, av, &serror);
	check_doublon(a, &serror);
	if (serror == NULL)
		exec_algo(&a, &b, lst_count(a));
	if (serror != NULL)
	{
		ft_putstr_fd(serror, 2);
		ft_putchar_fd('\n', 2);
		ret = 1;
	}
	return (ret);
}
