/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:27:43 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/15 11:30:57 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_getvar(char **env, char *var)
{
	size_t	len;
	char	*value;

	value = NULL;
	var = ft_strjoin(var, "=");
	len = ft_strlen(var);
	while (value == NULL && *env)
	{
		if (ft_strncmp(*env, var, len) == 0)
			value = (*env) + len;
		env++;
	}
	ft_memdel((void **)(&var));
	return (value);
}

void		ft_setvar(char ***env, char *var, char *value)
{
	size_t	len;
	size_t	i;
	char	**found;
	char	*tmp;

	var = ft_strjoin(var, "=");
	len = ft_strlen(var);
	found = NULL;
	i = 0;
	while (found == NULL && (*env)[i])
	{
		if (ft_strncmp((*env)[i], var, len) == 0)
		{
			found = (*env) + i;
			ft_memdel((void **)((*env) + i));
		}
		i++;
	}
	tmp = ft_strjoin(var, value);
	ft_memdel((void **)(&var));
	if (found)
		*found = tmp;
	else
		ft_pushtabs(env, tmp);
}

int			ft_unsetvar(char ***env, char *var)
{
	size_t	len;
	size_t	i;
	int		found;

	var = ft_strjoin(var, "=");
	len = ft_strlen(var);
	found = 0;
	i = 0;
	while (found == 0 && (*env)[i])
	{
		if (ft_strncmp((*env)[i], var, len) == 0)
			found = i;
		i++;
	}
	ft_memdel((void **)&var);
	if (found == 0)
		return (-1);
	ft_remtabs(env, found);
	return (0);
}
