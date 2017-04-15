/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:16:51 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/04 20:14:35 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <unistd.h>
#include <stdlib.h>
#include <ft_printf.h>

static char		**start_current(void)
{
	char **tab;

	tab = (char **)ft_memalloc(sizeof(char *) * 2);
	tab[0] = ft_strdup(".");
	tab[1] = NULL;
	return (tab);
}

static char		**copy_table(char **av, int ac)
{
	char	**tab;
	int		i;

	tab = (char **)ft_memalloc(sizeof(char *) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		tab[i] = ft_strdup(av[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static void		launch_ls(char **av, int nb, t_ls ls, t_sls *sls)
{
	char	**tab;

	sls->count = 0;
	sls->ok = 0;
	tab = av ? copy_table(av, nb) : start_current();
	ft_ls(tab, ls, "", sls);
	del_tab(tab);
}

int				main(int ac, char **av)
{
	int		i;
	t_ls	ls;
	t_sls	sls;

	i = 1;
	init_arg(&ls);
	ls.legal = "RPGCalorsdteimc1-";
	while (ac > 1 && i < ac && av[i][0] == '-')
		if (arg(&ls, av[i++]) == 0)
			return (1);
	if (i < ac)
		launch_ls(av + i, ac - i, ls, &sls);
	else
		launch_ls(NULL, 0, ls, &sls);
	if (ls.count)
		ft_printf("\nFiles count : %d\n", sls.count);
	return (sls.ok);
}
