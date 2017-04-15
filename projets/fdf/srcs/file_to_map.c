/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:45:48 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 19:03:04 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <unistd.h>
#include <fcntl.h>

static int			check_error(char *str, t_fdf *fdf)
{
	int		i;

	if (fdf->width && ft_count_word(str, " ") != fdf->width)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (!(ft_strchr("-+ ", str[i])) && !ft_isdigit(str[i]))
			return (-1);
		if (i > 0 && (str[i] == '-' || str[i] == '+') && str[i - 1] != ' ')
			return (-1);
		i++;
	}
	return (1);
}

static	int			add_value(char *data, t_fdf *fdf)
{
	int		z;

	z = ft_atoi(data);
	fdf->min_z = fmin(fdf->min_z, z);
	fdf->max_z = fmax(fdf->max_z, z);
	return (z);
}

static void			add(char *data, t_fdf *fdf)
{
	int *line;

	fdf->height += 1;
	if (fdf->width == 0)
	{
		fdf->map = (int **)ft_memalloc(sizeof(int*) * 1);
		fdf->width = ft_count_word(data, " ");
	}
	else
		fdf->map = (int **)ft_realloc((void**)&(fdf->map),
		sizeof(int*) * fdf->height);
	line = (int *)ft_memalloc(sizeof(int) * fdf->width);
	(fdf->map)[fdf->height - 1] = line;
	while (*data)
	{
		while (*data == ' ')
			data++;
		if (*data)
			*line = add_value(data, fdf);
		while (*data && *data != ' ')
			data++;
		line++;
	}
}

int					file_to_map(char *file, t_fdf *fdf)
{
	int		fd;
	char	*buf;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while (ft_gnl(fd, &buf) != 0)
	{
		if (check_error(buf, fdf) != 1)
		{
			ft_putstr_fd("ERROR : map file is wrong.\n", 2);
			del_tab(fdf);
			close(fd);
			return (-2);
		}
		add(buf, fdf);
	}
	close(fd);
	if (fdf->width == 0)
	{
		ft_putstr_fd("ERROR : map file is wrong.\n", 2);
		return (-2);
	}
	return (1);
}
