/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:09:17 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 15:07:06 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

static int		add_new(const int fd, int i, t_fdtable *t, int reset)
{
	if (reset)
	{
		t->state[i] = 0;
		t->len[i] = 0;
		ft_memdel((void *)&(t->data[i]));
	}
	else
	{
		t->fd = (int *)ft_realloc((void **)&(t->fd), sizeof(int) * (i + 2));
		t->fd[i] = fd;
		t->fd[i + 1] = -1;
		t->state = (int *)ft_realloc((void **)&(t->state),
		sizeof(int) * (i + 1));
		t->state[i] = 0;
		t->len = (int *)ft_realloc((void **)&(t->len), sizeof(int) * (i + 1));
		t->len[i] = 0;
		t->data = (char **)ft_realloc((void **)&(t->data),
		sizeof(char *) * (i + 1));
	}
	return (1);
}

static int		getindex(const int fd, t_fdtable *tab, int reset)
{
	int index;

	if (reset != 1 && tab->init == 0)
	{
		tab->init = 1;
		tab->fd = (int *)ft_memalloc(sizeof(int) * 2);
		tab->fd[0] = fd;
		tab->fd[1] = -1;
		tab->state = (int *)ft_memalloc(sizeof(int));
		tab->state[0] = 0;
		tab->len = (int *)ft_memalloc(sizeof(int));
		tab->len[0] = 0;
		tab->data = (char **)ft_memalloc(sizeof(char *));
	}
	index = 0;
	while (tab->fd[index] != fd && tab->fd[index] != -1)
		index++;
	if (tab->fd[index] == -1)
		add_new(fd, index, tab, 0);
	else if (reset)
		add_new(fd, index, tab, 1);
	return (index);
}

static char		*shift_line(t_fdtable *table, int i)
{
	int		len;
	char	*line;
	char	*tmp;

	len = 0;
	while (len < table->len[i] && table->data[i][len] != '\n')
		len++;
	line = ft_strsub(table->data[i], 0, len);
	tmp = table->data[i];
	table->data[i] = ft_strdup((table->data[i]) + len + 1);
	ft_memdel((void **)&tmp);
	if (table->len[i] <= 0 && table->state[i] == 2)
		table->state[i] = table->fd[i] == 0 ? 1 : 3;
	table->len[i] = table->len[i] - (len + 1);
	return (line);
}

int				read_it(const int fd, t_fdtable *tab, int index)
{
	int		ret;
	char	*buff;
	char	*tmp;

	buff = ft_strnew(BUFF_SIZE);
	while (ft_countchar(tab->data[index], '\n') == 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		tab->len[index] += ret;
		tmp = tab->data[index];
		tab->data[index] = ft_strjoin(tab->data[index], buff);
		ft_memdel((void **)&tmp);
		if (ret < BUFF_SIZE)
		{
			tab->state[index] = tab->fd[index] == 0 ? 1 : 2;
			return (0);
		}
	}
	ft_memdel((void **)(&buff));
	return (1);
}

int				ft_gnl(const int fd, char **line)
{
	static t_fdtable	table;
	int					status;
	int					index;

	if (line == NULL && table.init != 0)
	{
		getindex(fd, &table, 1);
		return (0);
	}
	if (fd < 0)
		return (-1);
	index = getindex(fd, &table, 0);
	if (table.state[index] == 0)
	{
		table.state[index] = 1;
		table.data[index] = ft_strnew(0);
	}
	if (table.state[index] == 1)
		status = read_it(fd, &table, index);
	if (table.state[index] != 3)
	{
		*line = shift_line(&table, index);
		return (table.state[index] == 3 ? 0 : 1);
	}
	return (0);
}
