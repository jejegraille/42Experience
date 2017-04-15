/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:08:12 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/22 18:57:27 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <signal.h>

int		minishell(t_gsh *data)
{
	char	*cmd;
	char	**av;

	data->error = 0;
	data->serror = "command not found";
	data->serror2 = "";
	data->ok = 0;
	cmd = ft_strnew(320);
	ft_putstr("\x1B[32mmsh$> \x1B[0m");
	gsh_read(cmd);
	av = conv_arg(data, cmd);
	if (*av)
	{
		gsh_exec(data, av);
		gsh_error(data);
	}
	ft_deltabs(av);
	ft_memdel((void **)(&cmd));
	return (data->exit);
}

int		main(void)
{
	t_gsh			data;
	extern char		**environ;
	char			*name;

	data.exit = 0;
	name = getenv("TERM");
	if (name == NULL)
	{
		ft_putstr_fd("Minishell abord : TERM undefined\n", 2);
		return (2);
	}
	tgetent(NULL, name);
	data.env = ft_tabsdup(environ);
	while (minishell(&data) == 0)
		;
	return (0);
}
