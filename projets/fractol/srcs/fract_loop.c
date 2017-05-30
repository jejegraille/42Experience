/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 14:19:03 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 12:28:34 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <libft.h>
#include <fractole.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

static void		father_work(t_image *cav, int fd, t_core *cores, int nbr_left)
{
	t_image	image;
	int		len[4];
	int		id;

	if (nbr_left != 0)
	{
		id = nbr_left - 1;
		image = cores->images[id];
		len[2] = image.data_len * image.s_p;
		len[1] = image.data_len * image.s_p;
		len[0] = 0;
		while (len[0] != len[1] &&
				(len[3] = read(fd, (char *)(image.data) + len[0], len[2])))
		{
			len[0] += len[3];
			len[2] = (len[2] > (len[1] - len[0])) ? len[1] - len[0] : len[2];
		}
		mx_mlx_image(&image);
		father_work(cav, fd, cores, nbr_left - 1);
	}
}

static void		child_work(t_graph *gr, t_core *cores, int id, int fd)
{
	pid_t		new;
	t_thread	thread;

	if (id != cores->nbr)
	{
		new = fork();
		if (new == 0)
			child_work(gr, cores, id + 1, fd);
		else
		{
			thread.pid = new;
			thread.fd = fd;
			paint(thread, &((cores->images)[id]), gr, id);
		}
	}
}

static void		init_core(int nb_c, t_core *cores, t_system *sys)
{
	t_image	*image;
	int		i;
	int		wi;
	int		he;

	if (cores->init == 0)
	{
		nb_c = nb_c < 1 ? 1 : nb_c;
		wi = sys->mx->width / nb_c;
		cores->width = wi;
		he = sys->mx->height;
		cores->nbr = nb_c;
		cores->init = 1;
		image = (t_image *)ft_memalloc(sizeof(t_image) * nb_c);
		i = -1;
		while (++i < nb_c)
		{
			(i == nb_c - 1) && (wi = wi + sys->mx->width - nb_c * wi);
			image[i] = get_mlx_image(wi, he);
			image[i].x = i * cores->width;
			image[i].y = 0;
			image[i].pivot = get_point(0, 0, 0);
		}
		cores->images = image;
	}
}

void			frac_loop(t_system *system, t_graph *gr)
{
	pid_t			father;
	int				fildes[2];
	static t_core	cores;

	init_core(8, &cores, system);
	if (pipe(fildes) == -1)
		perror("");
	father = fork();
	if (father > 0)
	{
		close(fildes[1]);
		father_work(&(system->mx->canvas), fildes[0], &cores, cores.nbr);
		wait(0);
		close(fildes[0]);
	}
	else
	{
		close(fildes[0]);
		child_work(gr, &cores, 0, fildes[1]);
		close(fildes[1]);
		exit(0);
	}
}
