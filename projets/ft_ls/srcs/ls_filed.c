/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_filed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:45:59 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/04 17:31:51 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>

static char			s_type(t_lfd *file)
{
	char	*end;

	if (file->type != 'd')
	{
		end = ft_strrchr(file->name, '.');
		if (ft_strlen(end) > 1)
		{
			if (ft_strequ(".c", end) || ft_strequ(".o", end))
				return (end[1]);
			if ((ft_strequ(".jpg", end)) || ft_strequ(".gif", end) ||
			ft_strequ(".png", end) || ft_strequ(".tiff", end))
				return ('i');
			if ((ft_strequ(".ogg", end)) || ft_strequ(".wav", end) ||
			ft_strequ(".mp3", end))
				return ('m');
			if ((ft_strequ(".tar", end)) || ft_strequ(".zip", end) ||
			ft_strequ(".rpm", end) || ft_strequ(".deb", end))
				return ('a');
		}
	}
	return ('-');
}

static char			type_file(mode_t mode)
{
	if (S_IFMT)
	{
		if (S_ISREG(mode))
			return ('-');
		if (S_ISDIR(mode))
			return ('d');
		if (S_ISCHR(mode))
			return ('c');
		if (S_ISBLK(mode))
			return ('b');
		if (S_ISFIFO(mode))
			return ('p');
		if (S_ISLNK(mode))
			return ('l');
		if (S_ISSOCK(mode))
			return ('s');
	}
	return ('-');
}

static void			part_b(char *name, t_lfd *fi, char time, struct stat buf)
{
	fi->stype = s_type(fi);
	if (time == 'a')
		fi->time = buf.st_atimespec.tv_sec;
	else if (time == 'c')
		fi->time = buf.st_ctimespec.tv_sec;
	else
		fi->time = buf.st_mtimespec.tv_sec;
	fi->dev = buf.st_rdev;
	if (fi->type != 'b' && fi->type != 'c')
		fi->attr = listxattr(name, NULL, 1, XATTR_NOFOLLOW);
	else
		fi->attr = 0;
}

int					ls_filed(char *name, t_lfd *fi, char time)
{
	struct stat		buf;

	fi->analysed = 0;
	if (lstat(name, &buf) == -1 && stat(name, &buf) == -1)
		return (-1);
	fi->lname = ft_strnew(200);
	readlink(name, fi->lname, 200);
	fi->name = ft_token_at(name, '/', -1);
	fi->path = name;
	fi->usr = getpwuid(buf.st_uid)->pw_name;
	fi->grp = getgrgid(buf.st_gid)->gr_name;
	fi->type = type_file(buf.st_mode);
	fi->chmod = (int)buf.st_mode;
	fi->link = buf.st_nlink;
	fi->size = buf.st_size;
	fi->bsize = buf.st_blocks;
	part_b(name, fi, time, buf);
	return (0);
}
