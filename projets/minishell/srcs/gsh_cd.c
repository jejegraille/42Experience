/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:19:53 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/28 14:54:11 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>
#include <sys/stat.h>

static void		error_dir(t_gsh *data, char *path)
{
	struct stat buf;
	int			chmod;

	data->serror = "error occured with: ";
	data->serror2 = path;
	if (stat(path, &buf) == -1)
		data->serror = "No such file or directory: ";
	else
	{
		chmod = (buf.st_mode / (8 * 8)) % 8;
		if (chmod == 0 || chmod == 2 || chmod == 4 || chmod == 6)
			data->serror = "permission denied: ";
	}
}

static void		set_pwd(t_gsh *data)
{
	char	*pwd;

	pwd = ft_strnew(320);
	getcwd(pwd, 320);
	set_var(&(data->env), "OLDPWD", get_var(data->env, "PWD"));
	set_var(&(data->env), "PWD", pwd);
	ft_memdel((void **)(&pwd));
}

int				gsh_cd(t_gsh *data, char *path)
{
	int		ok;
	int		del;
	char	*path2;

	data->ok = 1;
	if (!path || !(*path))
		path = get_var(data->env, "HOME");
	if (path && !(ft_strcmp(path, "-")))
		path = get_var(data->env, "OLDPWD");
	path2 = path;
	del = gsh_path(data, &path2);
	ok = chdir(path2);
	if (ok != -1)
		set_pwd(data);
	else
	{
		data->error = 1;
		error_dir(data, path2);
	}
	if (del)
		ft_memdel((void **)&path2);
	return (0);
}
