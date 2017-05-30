/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:01:57 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 16:58:59 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBX_H
# define LIBX_H

# include <mlx.h>
# include <string.h>
# include <math.h>

# define MX_EXIT 44

/*
**  DEFINE X_H
*/

# define KEYPRESSMASK	(1L<<0)
# define KEYRELEASEMASK	(1L<<1)
# define BUTTON3MOTIONMASK	(1L<<10)
# define BUTTON4MOTIONMASK	(1L<<11)
# define BUTTON5MOTIONMASK	(1L<<12)
# define BUTTONMOTIONMASK	(1L<<13)
# define KEYMAPSTATEMASK	(1L<<14)
# define EXPOSUREMASK	(1L<<15)
# define VISIBILITYCHANGEMASK	(1L<<16)
# define STRUCTURENOTIFYMASK	(1L<<17)
# define RESIZEREDIRECTMASK	(1L<<18)
# define SUBSTRUCTURENOTIFYMASK	(1L<<19)
# define BUTTONPRESSMASK	(1L<<2)
# define SUBSTRUCTUREREDIRECTMASK	(1L<<20)
# define FOCUSCHANGEMASK	(1L<<21)
# define PROPERTYCHANGEMASK	(1L<<22)
# define COLORMAPCHANGEMASK	(1L<<23)
# define BUTTONRELEASEMASK	(1L<<3)
# define ENTERWINDOWMASK	(1L<<4)
# define LEAVEWINDOWMASK	(1L<<5)
# define POINTERMOTIONMASK	(1L<<6)
# define POINTERMOTIONHINTMASK	(1L<<7)
# define BUTTON1MOTIONMASK	(1L<<8)
# define BUTTON2MOTIONMASK	(1L<<9)
# define NOEVENTMASK	0L
# define FOCUSOUT	10
# define KEYMAPNOTIFY	11
# define EXPOSE	12
# define GRAPHICSEXPOSE	13
# define NOEXPOSE	14
# define VISIBILITYNOTIFY	15
# define CREATENOTIFY	16
# define DESTROYNOTIFY	17
# define UNMAPNOTIFY	18
# define MAPNOTIFY	19
# define KEYPRESS	2
# define MAPREQUEST	20
# define REPARENTNOTIFY	21
# define CONFIGURENOTIFY	22
# define CONFIGUREREQUEST	23
# define GRAVITYNOTIFY	24
# define RESIZEREQUEST	25
# define CIRCULATENOTIFY	26
# define CIRCULATEREQUEST	27
# define PROPERTYNOTIFY	28
# define SELECTIONCLEAR	29
# define KEYRELEASE	3
# define SELECTIONREQUEST	30
# define SELECTIONNOTIFY	31
# define COLORMAPNOTIFY	32
# define CLIENTMESSAGE	33
# define MAPPINGNOTIFY	34
# define LASTEVENT	35
# define BUTTONPRESS	4
# define BUTTONRELEASE	5
# define MOTIONNOTIFY	6
# define ENTERNOTIFY	7
# define LEAVENOTIFY	8
# define FOCUSIN	9

typedef struct		s_key_l
{
	int				key;
	struct s_key_l	*next;
}					t_key_l;

typedef struct		s_rgba
{
	int	r;
	int	g;
	int	b;
	int	a;
}					t_rgba;

typedef struct		s_point
{
	double	x;
	double	y;
	double	z;
}					t_point;

typedef struct		s_rec
{
	t_point	tl;
	t_point	br;
	double	width;
	double	height;
}					t_rec;

typedef struct		s_tri
{
	t_point a;
	t_point b;
	t_point c;
}					t_tri;

typedef struct		s_line
{
	double	a;
	double	b;
	double	c;
	t_point	pa;
	t_point	pb;
	double	l;
}					t_line;

typedef struct		s_child
{
	struct s_image	*image;
	struct s_child	*next;
}					t_child;

typedef struct		s_image
{
	int				x;
	int				y;
	t_point			pivot;
	double			rot;
	void			*ptr;
	int				*data;
	int				*render;
	int				data_len;
	int				s_l;
	int				s_p;
	int				edn;
	int				width;
	int				height;
	t_child			*child;
	struct s_image	*parent;
}					t_image;

typedef struct		s_mx
{
	int		init;
	int		width;
	int		height;
	void	*id;
	void	*win;
	t_image	canvas;
}					t_mx;

/*
**  MOUSE DEFINITION
*/

# define M_LEFT		1
# define M_RIGHT	2
# define M_WUP		7
# define M_WDOWN	4

typedef struct		s_mouse
{
	int		x;
	int		y;
	t_point	pos_rel;
	int		click;
}					t_mouse;

/*
**  KEYBOARD DEFINITION
*/

# define K_LEFT		123
# define K_RIGHT	124
# define K_DOWN		125
# define K_UP		126

typedef struct		s_keybo
{
	int		keycount;
	int		key;
	int		onkey;
	t_key_l	*down;
}					t_keybo;

typedef struct		s_system
{
	t_mx	*mx;
	t_mouse *mouse;
	t_keybo	*keybo;
	int		width;
	int		height;
	int		render_off;
	int		event_win_close;
}					t_system;

t_rgba				get_rgba(int r, int g, int b, int a);
t_tri				get_tri(t_point a, t_point b, t_point c);
t_line				get_line(t_point a, t_point b);
t_rec				get_rec(t_point top_left, t_point bot_right);
t_point				get_point(double x, double y, double z);
t_image				get_image(int width, int height);
t_image				get_mlx_image(int width, int height);
void				del_image(t_image *image);
t_mx				*mx_init(int width, int height, char *title);
t_system			*get_system(t_system *save);
t_mx				*get_mx(t_mx *save);
t_mouse				*get_mouse(t_mouse *save);
t_keybo				*get_keybo(t_keybo *save);
double				get_distance(t_point a, t_point b);
int					rgba_toi(t_rgba color);
int					mx_key_down(int key);
int					mx_rgba(int red, int green, int blue, int alpha);
int					mx_addchild(t_image *parent, t_image *child);
void				mx_string(char *str, t_point o, int color);
void				mx_point(t_image image, t_point p, int color);
void				mx_rec(t_image *image, t_rec rec, int color);
void				mx_render_point(t_image image, t_point p, int color);
void				mx_line(t_image image, t_line line, int color);
void				mx_tri(t_image image, t_tri t, int color);
void				mx_image(t_image *source, t_image *image);
void				mx_mlx_image(t_image *image);
void				mx_render();
int					mx_hook_k(int key, void *param);
int					mx_keybo_release(int key, void *param);
int					mx_hook_l(void *param);
int					mx_hook_win_close(void *param);
int					mx_hook_mouse(int button, int x, int y, void *param);
void				mx_start();
void				mx_loop(t_system *system);
t_point				mx_to3d(t_point a);
int					mx_motion_notify(int x, int y, void *param);

#endif
