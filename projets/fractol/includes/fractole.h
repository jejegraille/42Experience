/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractole.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:42:03 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 12:46:35 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLE_H
# define FRACTOLE_H

# include <libx.h>

typedef struct	s_par
{
	int		fractale;
}				t_par;

typedef struct	s_core
{
	int		init;
	int		nbr;
	int		width;
	t_image *images;
}				t_core;

typedef struct	s_thread
{
	int		pid;
	int		fd;
}				t_thread;

typedef struct	s_graph
{
	int				init;
	int				it_max;
	int				debug;
	int				view;
	t_rec			screen;
	t_point			center;
	t_point			center_d;
	int				mouse_var;
	t_point			mouse_r;
	t_point			scale;
	t_point			scale_d;
	int				theme;
	double			sine;
	int				sine_step;
	t_rgba			rgb;
	int				fct_nbr;
	int				(*fct)(t_point, struct s_graph *gr, t_mx *mx);
}				t_graph;

typedef int		(*t_fct)(t_point, t_graph *, t_mx *mx);

typedef struct	s_algo
{
	int		it;
	int		limit;
	int		it_max;
	double	zr;
	double	zi;
	double	z;
	double	cr;
	double	ci;
}				t_algo;

void			nextview(t_graph *gr);
void			change_view(t_graph *gr, t_point center, double sx, double sy);
void			paint(t_thread thread, t_image *image, t_graph *gr, int id);
void			frac_loop(t_system *system, t_graph *gr);
t_par			*get_par(t_par *par);
void			init_graph(t_graph *gr);
void			set_screen(t_graph *gr);
void			get_next_fct(t_graph *gr);
int				fct_mandelbrot(t_point pix, t_graph *gr, t_mx *mx);
int				fct_fusee(t_point pix, t_graph *gr, t_mx *mx);
int				fct_julia(t_point pix, t_graph *gr, t_mx *mx);
int				fct_burning_ship(t_point pix, t_graph *gr, t_mx *mx);
int				fct_burning_bird(t_point pix, t_graph *gr, t_mx *mx);
void			update(t_graph *gr);
void			set_next_theme(t_graph *gr);
void			paste_image(t_image *canvas, t_image *image);
void			put_usage(int count);
#endif
