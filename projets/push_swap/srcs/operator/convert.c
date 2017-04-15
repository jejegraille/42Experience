/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 11:13:44 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/05 10:23:24 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>
#include <libft.h>

void		convert(t_lst **start, char **av, char **serror)
{
	t_lst	*new;
	int		i;
	int		i2;
	char	**tb;

	i = 0;
	*start = NULL;
	while (av[++i] && new != NULL)
	{
		tb = ft_split_c(av[i], " \t\v");
		i2 = -1;
		while (tb[++i2])
		{
			new = new_elem(tb[i2], serror);
			if (new != NULL)
				add_elem(start, new);
		}
		ft_deltabs(tb);
	}
}
