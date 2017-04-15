/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_addpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:22:14 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/26 18:06:10 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>
#include <unistd.h>

static int	error_path(t_gsh *data, char **av, char *path)
{
	int		error;
	size_t	len;

	error = 0;
	len = ft_tablen((void **)av);
	if (len != 2)
	{
		data->error = 1;
		data->serror = "usage: addpath path";
		error = 1;
	}
	else if (access(path, X_OK) == -1)
	{
		data->error = 1;
		data->serror = path;
		data->serror2 = " : not found or permission denied";
		error = 1;
	}
	return (error);
}

void		gsh_addpath(t_gsh *data, char **av)
{
	char	*old;
	char	*new;
	char	*path;
	int		del;

	data->ok = 1;
	path = av[1];
	del = gsh_path(data, &path);
	if (error_path(data, av, path) == 0)
	{
		old = get_var(data->env, "PATH");
		if (old == NULL)
			set_var(&(data->env), "PATH", path);
		else
		{
			old = ft_strjoin(old, ":");
			new = ft_strjoin(old, path);
			set_var(&(data->env), "PATH", new);
			ft_memdel((void **)&new);
			ft_memdel((void **)&old);
		}
	}
	if (del)
		ft_memdel((void **)&path);
}
