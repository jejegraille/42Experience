/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:13:25 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 13:02:31 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libx.h>
#include <unistd.h>
#include <fractole.h>

static int		check_frac(char *name)
{
	int		ret;
	char	*check_name;

	ret = -1;
	if (*name != '\0')
	{
		check_name = ft_strdup(name);
		ft_str_tolower(check_name);
		!(ft_strcmp(check_name, "mandelbrot")) && (ret = 0);
		!(ft_strcmp(check_name, "1")) && (ret = 0);
		!(ft_strcmp(check_name, "julia")) && (ret = 1);
		!(ft_strcmp(check_name, "2")) && (ret = 1);
		!(ft_strcmp(check_name, "burning_ship")) && (ret = 2);
		!(ft_strcmp(check_name, "3")) && (ret = 2);
		!(ft_strcmp(check_name, "burning_bird")) && (ret = 3);
		!(ft_strcmp(check_name, "4")) && (ret = 3);
		!(ft_strcmp(check_name, "rocket")) && (ret = 4);
		!(ft_strcmp(check_name, "5")) && (ret = 4);
		ft_memdel((void **)&check_name);
	}
	return (ret);
}

static char		**get_choix(void)
{
	char **tab;

	tab = (char **)ft_memalloc(sizeof(char *) * 6);
	tab[0] = "Julia";
	tab[1] = "Mandelbrot";
	tab[2] = "Burning_ship";
	tab[3] = "Burning_bird";
	tab[4] = "Rocket";
	tab[5] = NULL;
	return (tab);
}

static int		new_frac(char *frac_name, char **tab)
{
	t_mx	*mx;
	t_par	*par;
	int		num;
	pid_t	father;

	num = check_frac(frac_name);
	if (num != -1)
	{
		father = fork();
		if (father == 0)
		{
			ft_memdel((void **)&(tab));
			par = get_par(NULL);
			par->fractale = num;
			mx = mx_init(600, 600, "test");
			mx_start();
		}
		return (1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	char	**tab;
	char	**tmp;
	int		i;
	int		count;

	count = 0;
	if (ac == 2 && ft_strcmp(av[1], "-pick") == 0)
	{
		tmp = get_choix();
		tab = ft_select(tmp);
		if (tmp != NULL)
			ft_memdel((void **)&tmp);
	}
	else if (ac == 1)
	{
		put_usage(count);
		return (0);
	}
	else
		tab = ft_tabsdup(++av);
	i = -1;
	while (tab != NULL && tab[++i] != NULL)
		count += new_frac(tab[i], tab);
	put_usage(count);
	return (0);
}
