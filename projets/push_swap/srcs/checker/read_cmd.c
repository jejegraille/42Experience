/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:59:09 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/01 16:11:02 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <unistd.h>

static t_fct	find_action(char *cmd)
{
	t_fct fct;

	fct = NULL;
	(ft_strcmp("ra", cmd) == 0) && (fct = &ra);
	(ft_strcmp("rb", cmd) == 0) && (fct = &rb);
	(ft_strcmp("rra", cmd) == 0) && (fct = &rra);
	(ft_strcmp("rrb", cmd) == 0) && (fct = &rrb);
	(ft_strcmp("rrr", cmd) == 0) && (fct = &rrr);
	(ft_strcmp("rr", cmd) == 0) && (fct = &rr);
	(ft_strcmp("pa", cmd) == 0) && (fct = &pa);
	(ft_strcmp("pb", cmd) == 0) && (fct = &pb);
	(ft_strcmp("sa", cmd) == 0) && (fct = &sa);
	(ft_strcmp("sb", cmd) == 0) && (fct = &sb);
	(ft_strcmp("ss", cmd) == 0) && (fct = &ss);
	return (fct);
}

t_fct			read_cmd(char **ser)
{
	char	*cmd;
	t_fct	fct;

	fct = NULL;
	*ser = NULL;
	ft_gnl(0, &cmd);
	if (ft_strlen(cmd) != 0)
	{
		if ((fct = find_action(cmd)) == NULL)
			*ser = "Error : wrong command";
	}
	ft_memdel((void **)&cmd);
	return (fct);
}
