/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:55:21 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/29 11:58:40 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <unistd.h>

static int		check_cmd(char *cmd)
{
	if (cmd[0] == 32)
		return (cmd[0]);
	if (cmd[0] == 27 && cmd[1] == 91)
		return (cmd[2] + 1000);
	if (cmd[0] == 27 && cmd[1] != 91)
		return (1000);
	if (cmd[0] == 127 || cmd[0] == 126)
		return (1001);
	if (cmd[0] == 10)
		return (1002);
	if (cmd[0] == -10)
		return (999);
	if (cmd[0] == 1 || cmd[0] == 4)
		return (cmd[0]);
	return (-1);
}

int				fts_read(void)
{
	char	buf[3];
	int		cmd;

	cmd = -1;
	while (cmd == -1)
	{
		if (read(0, &buf, 3) == -1)
			return (-1);
		cmd = check_cmd(buf);
		buf[1] = '\0';
		buf[2] = '\0';
	}
	return (cmd);
}
