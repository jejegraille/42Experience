/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:52:11 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/26 18:09:17 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>

int		gsh_path(t_gsh *data, char **path)
{
	int		special;
	char	*home;

	special = 0;
	if (path && *path && **path && **path == '~')
	{
		special = 1;
		*path = *path + 1;
		home = get_var(data->env, "HOME");
		*path = home ? ft_strjoin(home, *path) : ft_strdup(*path);
	}
	return (special);
}
