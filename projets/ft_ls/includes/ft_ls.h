/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:31:43 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/05 11:54:01 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <libft.h>
# include <sys/types.h>

typedef struct		s_lfd
{
	char	*name;
	char	*path;
	long	time;
	int		link;
	int		dev;
	int		chmod;
	char	type;
	char	stype;
	size_t	size;
	ssize_t	attr;
	char	*usr;
	char	*grp;
	char	*lname;
	int		bsize;
	int		analysed;
	int		valide;
}					t_lfd;

typedef	struct		s_fl
{
	char		*name;
	struct s_fl	*next;
}					t_fl;

typedef struct		s_ls
{
	int		first;
	int		a;
	int		t;
	int		l;
	int		rec;
	int		r;
	int		f;
	int		s;
	int		c;
	int		o;
	int		color;
	int		e;
	int		d;
	int		i;
	int		m;
	int		path;
	int		count;
	int		out;
	int		only;
	int		len;
	int		ok;
	char	*legal;
}					t_ls;

typedef struct		s_sls
{
	int		count;
	int		tmpcount;
	int		ok;
}					t_sls;

typedef struct		s_align
{
	int		usr;
	int		grp;
	int		size;
	int		link;
	int		total;
	int		count;
}					t_align;

typedef struct		s_sort
{
	t_lfd	*tmp_max;
	t_lfd	*tmp_min;
	int		i;
	int		end;
	int		start;
	int		len;
	int		ind_max;
	int		ind_min;
}					t_sort;

int					arg(t_ls *ls, char *arg);
void				del_tab(char **tab);
void				del_files(t_lfd **files);
int					print_info(t_lfd file, t_align al);
void				init_arg(t_ls *ls);
int					init(t_ls *ls, char *arg);
int					vald(t_lfd file, t_ls ls);
int					valf(t_lfd file, t_ls ls);
void				ls_analys(t_lfd *file, t_align *ali, t_ls ls);
void				init_ls_analys(t_align *al);
int					ls_filed(char *name, t_lfd *fi, char time);
void				sort_tab(t_lfd **tab, t_ls ls);
void				ft_ls(char **tab, t_ls ls, char *path, t_sls *sls);
t_lfd				**file_tab(char **tab, t_ls *ls, t_align *al, t_sls *sls);
t_fl				*fl_new(t_fl *start, char *name);
int					print_filed(t_lfd fi, t_ls ls, t_align al);
int					is_exe(mode_t mod, char who);

#endif
