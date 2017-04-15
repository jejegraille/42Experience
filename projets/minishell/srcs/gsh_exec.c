/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:11:13 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/01 12:18:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>
#include <unistd.h>
#include <sys/stat.h>

static int		test_access(t_gsh *data, char *path)
{
	int			ok;

	ok = 1;
	if (access(path, F_OK) == -1)
	{
		ok = 0;
		data->error = 1;
	}
	else if (access(path, X_OK) == -1)
	{
		ok = 0;
		data->error = 1;
		data->serror = "permission denied";
	}
	return (ok);
}

static char		*next_ex(char **path, char *cmd)
{
	char	*tmp;
	char	*ex;
	char	*find;
	size_t	len;

	find = ft_strchr(*path, ':');
	len = ft_strlen(*path) - ft_strlen(find) + 1;
	tmp = ft_strnew(len);
	ft_strncpy(tmp, *path, len);
	tmp[len - 1] = '/';
	ex = ft_strjoin(tmp, cmd);
	ft_memdel((void **)(&tmp));
	*path = find ? find + 1 : find;
	return (ex);
}

static void		new_proc(t_gsh *data, char **av)
{
	char	*path;
	char	*ex;

	data->exit = 1;
	if (ft_strchr(data->cmd, '/'))
	{
		if (test_access(data, data->cmd))
			execve(data->cmd, av, data->env);
	}
	else
	{
		path = get_var(data->env, "PATH");
		while (path && *path)
		{
			ex = next_ex(&path, av[0]);
			if (test_access(data, ex))
				execve(ex, av, data->env);
			ft_memdel((void **)(&ex));
		}
	}
	data->error = 1;
}

void			gsh_exec(t_gsh *data, char **av)
{
	pid_t	father;

	data->cmd = av[0];
	gsh_fonct(data, av);
	if (data->ok == 0)
	{
		father = fork();
		if (father > 0)
			wait(0);
		else
			new_proc(data, av);
	}
}
