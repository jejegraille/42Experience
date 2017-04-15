/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:09:17 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/01 15:09:52 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

static int		add_new(const int fd, int i, t_fdtable *tab)
{
	tab->fd = (int *)ft_realloc((void **)&(tab->fd), sizeof(int) * (i + 2));
	tab->fd[i] = fd;
	tab->fd[i + 1] = -1;
	tab->state = (int *)ft_realloc((void **)&(tab->state),
	sizeof(int) * (i + 1));
	tab->state[i] = 0;
	tab->len = (int *)ft_realloc((void **)&(tab->len), sizeof(int) * (i + 1));
	tab->len[i] = 0;
	tab->data = (char **)ft_realloc((void **)&(tab->data),
	sizeof(char *) * (i + 1));
	return (1);
}

static int		getindex(const int fd, t_fdtable *tab)
{
	int index;

	if (tab->init == 0)
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
		add_new(fd, index, tab);
	return (index);
}

static char		*shift_line(t_fdtable *table, int index)
{
	int		len;
	char	*line;
	char	*tmp;

	len = 0;
	while (len < table->len[index] && table->data[index][len] != '\n')
		len++;
	line = ft_strsub(table->data[index], 0, len);
	tmp = table->data[index];
	table->data[index] = ft_strdup((table->data[index]) + len + 1);
	ft_memdel((void **)&tmp);
	if (table->len[index] <= 0 && table->state[index] == 2)
		table->state[index] = 3;
	table->len[index] -= len + 1;
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
			tab->state[index] = 2;
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

	if (fd < 0 || line == NULL)
		return (-1);
	index = getindex(fd, &table);
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
