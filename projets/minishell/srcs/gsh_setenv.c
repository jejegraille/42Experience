/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:37:45 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/14 14:55:15 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>

static int		c_special(char *str)
{
	int ok;
	int	i;

	ok = 0;
	i = -1;
	while (!ok && str[++i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '-' && str[i] != '_')
			ok = 1;
	}
	return (ok);
}

static int		error_char(t_gsh *data, char **av)
{
	int ok;

	ok = 0;
	if (c_special(av[1]))
	{
		ok = 1;
		data->error = 1;
		data->serror = "characters special unaviable for VAR_NAME";
	}
	return (ok);
}

static int		error_len(t_gsh *data, char **av)
{
	int		ok;
	size_t	len;

	ok = 0;
	len = ft_tablen((void **)av);
	if (len < 2 && (ok = 1))
		data->serror = "not enouth arguments";
	if (len > 4 && (ok = 1))
		data->serror = "too many arguments";
	if (ok)
	{
		data->error = 1;
		data->serror2 = "\nusage: setenv VAR_NAME [VALUE] [overwright]";
	}
	return (ok);
}

void			gsh_setenv(t_gsh *data, char **av)
{
	int		over;
	int		len;

	over = 0;
	data->ok = 1;
	if (error_len(data, av) == 0 && error_char(data, av) == 0)
	{
		len = ft_tablen((void **)av);
		if (len > 2 && (av[3] != NULL && ft_stronly(av[3], "0") != NULL))
			over = 1;
		if (get_var(data->env, av[1]) == NULL || over == 1)
			set_var(&(data->env), av[1], av[2]);
	}
}
