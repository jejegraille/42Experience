/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 13:09:25 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/26 12:51:48 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <sys/ttydefaults.h>

static void		myset_term()
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
}

static t_cmd		*new_cmd(void)
{
	t_cmd *new;

	new = (t_cmd*)ft_memalloc(sizeof(t_cmd));
	new->c = '\0';
	new->next = NULL;
	new->back = NULL;
	return (new);
}

static void		supr_cmd(t_cmd *cur)
{
	cur->back->next = cur->next;
	if (cur->next != NULL)
		cur->next->back = cur->back;
	ft_memdel((void **)&cur);
}

static void		go_right()
{
	int i;
	int	width;

	width = tgetnum("co");
	i = -1;
	while (++i < width)
		ft_cap("nd", 0);
}

static void		my_move(int cmd, int *i, t_cmd *start, t_cmd **cur)
{
	if (cmd == 67 && (*cur)->next != NULL)
	{
		*cur = (*cur)->next;
		*i += 1;
		if ((*i + 6) % tgetnum("co") == 0)
		{
			ft_cap("do", 0);
			ft_cap("cr", 0);
		}
		else
			ft_cap("nd", 0);
		if ((*cur)->next == NULL)
			ft_cap("ei", 0);
	}
	if (cmd == 68 && (*cur) != start)
	{
		*cur = (*cur)->back;
		if ((*i + 6) % tgetnum("co") == 0)
		{
			ft_cap("up", 0);
			go_right();
		}
		else
			ft_cap("le", 0);
		ft_cap("im", 0);
		*i -= 1;
	}
}

static void		put_list_c(t_cmd *start, int i)
{
	int i2;

	i2 = -1;
	while (++i2 < i)
		start = start->next;
	ft_putchar(start->c);
}

static void		ins_c(t_cmd *start, int i, int len)
{
	int	i2;
	int	width;
	int	psize;

	psize = 6;
	width = tgetnum("co");
	ft_cap("im", 0);
	if (len + psize > width)
	{
		ft_cap("sc", 0);
		i2 = width - psize;
		while (i2 < i)
			i2 += width;
		ft_cap("cr", 0);
		while (i2 < len)
		{
			ft_cap("do", 0);
			put_list_c(start, i2);
			i2 += width;
		}
		ft_cap("rc", 0);
	}
}

static void		del_c(t_cmd *start, int i, int len)
{
	int	i2;
	int	width;
	int	psize;

	psize = 6;
	width = tgetnum("co");
	if ((i + 6) % width == width - 1)
	{
		ft_cap("up", 0);
		go_right();
		ft_cap("ei", 0);
		put_list_c(start, i);
	}
	else
	{
		ft_cap("le", 0);
		ft_cap("dc", 0);
	}
	if (len + psize > width)
	{
		ft_cap("sc", 0);
		i2 = width * (1 + (int)((i + psize)/ width)) - psize - 1;
		while (i2 < len)
		{
			go_right();
			ft_cap("ei", 0);
			if (i2 < len)
				put_list_c(start, i2);
			else
				ft_putchar(' ');
			ft_cap("cr", 0);
			ft_cap("do", 0);
			ft_cap("dc", 0);
			i2 += width;
		}
		ft_cap("rc", 0);
	}
}

static void		gsh_read_(t_cmd **start, t_cmd *cur, int i, int len)
{
	char	c[3];
	t_cmd	*tmp;

	read(0, c, 3);
	if (c[0] == 127)
	{
		if (*start != cur)
		{
			tmp = cur->back;
			supr_cmd(cur);
			cur = tmp;
			i--;
			len--;
			del_c(*start, i, len);
			if (cur->next == NULL)
			{
				cur->c = '\0';
				ft_cap("ei", 0);
			}
			else
				ft_cap("im", 0);
		}
	}
	if (c[0] == 27 && c[1] == 91)
		my_move(c[2], &i,*start, &cur);
	if (ft_isprint(c[0]))
	{
		tmp = new_cmd();
		tmp->back = cur->back;
		tmp->next = cur;
		if (cur->back == NULL)
			*start = tmp;
		else
			cur->back->next = tmp;
		cur->back = tmp;
		tmp->c = c[0];
		ft_putchar(c[0]);
		i++;
		len++;
		ins_c(*start, i, len);
		if ((i + 6) % tgetnum("co") == 0)
		{
			ft_cap("cr", 0);
			ft_cap("do", 0);
		}
	}
	if (c[0] != '\n')
		gsh_read_(start, cur, i, len);
}

void			gsh_read(char *cmd)
{
	struct termios	term;
	t_cmd			*start;
	t_cmd			*tmp;
	int				i;

	start = new_cmd();
	tcgetattr(0, &term);
	myset_term();
	ft_cap("RA", 0);
	gsh_read_(&start, start, 0, 0);
	tcsetattr(0, TCSANOW, &term);
	i = 0;
	while (start != NULL && i < 320)
	{
		tmp = start;
		cmd[i++] = start->c;
		start = start->next;
		ft_memdel((void **)&tmp);
	}
	ft_cap("ei", 0);
	ft_putchar('\n');
	END(cmd)
}
