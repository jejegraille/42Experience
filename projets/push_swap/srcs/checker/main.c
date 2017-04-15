/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 14:35:14 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/05 10:24:19 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int		main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;
	char	*serror;
	t_fct	fct;
	int		ret;

	ret = 0;
	if (ac == 1)
		return (1);
	serror = NULL;
	convert(&a, av, &serror);
	check_doublon(a, &serror);
	while (serror == NULL && (fct = read_cmd(&serror)) != NULL)
		fct(&a, &b);
	if (serror == NULL)
		ft_putstr(check_order(a, b) ? "OK\n" : "KO\n");
	if (serror != NULL)
	{
		ft_putstr_fd(serror, 2);
		ft_putchar_fd('\n', 2);
		ret = 1;
	}
	return (ret);
}
