/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:43:21 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/29 13:03:17 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>
# include <libft.h>

typedef struct sigaction	t_sig;

typedef struct				s_fts
{
	int		len;
	int		page;
	int		lcurs;
	int		maxlen;
	int		cw;
	int		w;
	int		h;
	int		tw;
	int		ok;
	char	*tname;
	char	*eta;
	int		curs;
	int		select_count;
	int		exit;
}							t_fts;

typedef struct				s_data
{
	int				fd;
	int				sig_t;
	struct termios	term;
}							t_data;

t_data	g_fts;

char						**ft_select(char **tabl);
int							fts_cap(char *cap);
int							fts_cap_write(char *str, int x, int y);
void						fts_analys(t_fts *data, char **tabl);
int							fts_update(t_fts *data, char **tabl);
void						fts_print(t_fts *data, char **tabl);
int							fts_read(void);
void						fts_ex_cmd(int cmd, t_fts *data, char **tabl);
char						**fts_final(t_fts *data, char **tabl);
void						fts_init_signal(void);
void						fts_reset_signal(int cont);
void						fts_signal(t_fts *data);
int							fts_reset_term(void);
int							fts_set_term(void);
void						fts_sig_cnt(int sig);
void						fts_sig_cc(int sig);
void						fts_sig_win(int sig);
void						fts_sig_cz(int sig);
void						fts_cmd_select(t_fts *data);
void						*fts_error(char *str_error);

#endif
