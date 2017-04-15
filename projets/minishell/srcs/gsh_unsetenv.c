/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:48:09 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/26 16:48:58 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>

int			gsh_unsetenv(t_gsh *data, char **av)
{
	size_t len;

	data->ok = 1;
	len = ft_tablen((void **)av);
	if (len != 2)
	{
		data->error = 1;
		data->serror = "usage: unsetenv var_name";
	}
	else if (del_var(&(data->env), av[1]) == -1)
	{
		data->error = 1;
		data->serror = "variable undefined";
		return (-1);
	}
	return (0);
}
