/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_fonct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:32:35 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/01 13:49:08 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>
#include <unistd.h>

int		gsh_fonct(t_gsh *data, char **av)
{
	int	ok;

	ok = 0;
	if (!ok && ft_strcmp(av[0], "env") == 0 && (ok = 1))
	{
		data->ok = 1;
		put_env(data->env);
	}
	if (!ok && ft_strcmp(ft_str_tolower(av[0]), "echo") == 0 && (ok = 1))
		gsh_echo(data, av);
	if (!ok && ft_strcmp(av[0], "addpath") == 0 && (ok = 1))
		gsh_addpath(data, av);
	if (!ok && ft_strcmp(av[0], "cd") == 0 && (ok = 1))
		gsh_cd(data, av[1]);
	if (!ok && ft_strcmp(av[0], "setenv") == 0 && (ok = 1))
		gsh_setenv(data, av);
	if (!ok && ft_strcmp(av[0], "unsetenv") == 0 && (ok = 1))
		gsh_unsetenv(data, av);
	if (!ok && ft_strcmp(av[0], "exit") == 0 && (ok = 1))
	{
		data->ok = 1;
		data->exit = 1;
	}
	return (data->ok);
}
