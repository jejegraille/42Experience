/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:59:05 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/28 21:21:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>

static char				type_file(mode_t mode)
{
	int grandeur;

	grandeur = 8 * 8 * 8;
	mode /= grandeur;
	mode *= grandeur;
	if (mode == S_IFMT)
		return ('-');
	if (mode == S_IFIFO)
		return ('p');
	if (mode == S_IFDIR)
		return ('d');
	if (mode == S_IFBLK)
		return ('b');
	if (mode == S_IFLNK)
		return ('l');
	if (mode == S_IFSOCK)
		return ('s');
	if (mode == S_IFCHR)
		return ('c');
	return ('-');
}

static char				*droit(mode_t mode)
{
	char	*droit;
	int		c;

	droit = ft_strnew(10);
	c = mode % 8;
	droit[6] = (c == 0 || c == 1 || c == 2 || c == 3) ? '-' : 'r';
	droit[7] = (c == 0 || c == 1 || c == 4 || c == 5) ? '-' : 'w';
	droit[8] = (c == 0 || c == 2 || c == 4 || c == 6) ? '-' : 'x';
	c = (mode / 8) % 8;
	droit[3] = (c == 0 || c == 1 || c == 2 || c == 3) ? '-' : 'r';
	droit[4] = (c == 0 || c == 1 || c == 4 || c == 5) ? '-' : 'w';
	droit[5] = (c == 0 || c == 2 || c == 4 || c == 6) ? '-' : 'x';
	c = (mode / (8 * 8)) % 8;
	droit[0] = (c == 0 || c == 1 || c == 2 || c == 3) ? '-' : 'r';
	droit[1] = (c == 0 || c == 1 || c == 4 || c == 5) ? '-' : 'w';
	droit[2] = (c == 0 || c == 2 || c == 4 || c == 6) ? '-' : 'x';
	return (droit);
}

static char				*ls_time(__darwin_time_t *sec)
{
	char	*str;
	char	*tmp;
	size_t	len;
	time_t	ltime;
	int		ecart;

	tmp = ctime(sec);
	time(&ltime);
	ecart = 60 * 60 * 24 * 31 * 6;
	if (ltime - *sec >= ecart || *sec - ltime <= -ecart)
	{
		str = ft_strdup(tmp + 4);
		len = ft_strlen(str);
		ft_memcpy((void *)str + len - 14, str + len - 6, 5);
		str[len - 9] = '\0';
	}
	else
	{
		str = ft_delwords(tmp, 1);
		len = ft_strlen(str);
		while (str[len] != ':')
			len--;
		str[len] = 0;
	}
	return (str);
}

void					dev_ma_mi(int dev, t_fd *file)
{
	char *hex;
	char *tmp;

	tmp = ft_itoa(dev);
	hex = ft_convert_base(tmp, BASE_DEC, BASE_HEX);
	ft_memdel((void **)&tmp);
	file->devma = hex[0];
	file->devmi = hex[ft_strlen(hex) - 1];
}

int						ft_filed(char *name, t_fd *fi)
{
	struct stat		buf;

	fi->analysed = 0;
	if (lstat(name, &buf) == -1 && stat(name, &buf) == -1)
		return (-1);
	fi->lname = ft_strnew(20);
	readlink(name, fi->lname, 20);
	fi->name = ft_token_at(name, '/', -1);
	fi->path = name;
	fi->usr = getpwuid(buf.st_uid)->pw_name;
	fi->grp = getgrgid(buf.st_gid)->gr_name;
	fi->type = type_file(buf.st_mode);
	fi->chmod = droit(buf.st_mode);
	fi->link = buf.st_nlink;
	fi->size = buf.st_size;
	fi->ts_a = ls_time(&(buf.st_atimespec.tv_sec));
	fi->ts_m = ls_time(&(buf.st_mtimespec.tv_sec));
	fi->ts_c = ls_time(&(buf.st_ctimespec.tv_sec));
	fi->ti_a = buf.st_atimespec.tv_sec;
	fi->ti_m = buf.st_mtimespec.tv_sec;
	fi->ti_c = buf.st_ctimespec.tv_sec;
	fi->bsize = buf.st_blocks;
	dev_ma_mi(buf.st_rdev, fi);
	return (0);
}
