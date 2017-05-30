/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:12:58 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/29 13:06:30 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <ft_select.h>
#include <sys/ioctl.h>

void	fts_init_signal(void)
{
	signal(SIGTSTP, fts_sig_cz);
	signal(SIGINT, fts_sig_cc);
	signal(SIGCONT, fts_sig_cnt);
	signal(SIGWINCH, fts_sig_win);
}

void	fts_reset_signal(int cont)
{
	signal(SIGTSTP, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	if (cont)
		signal(SIGCONT, SIG_DFL);
	signal(SIGWINCH, SIG_DFL);
}

void	fts_signal(t_fts *data)
{
	if (g_fts.sig_t == 0)
		data->exit = 1;
	if (g_fts.sig_t == 1)
	{
		fts_reset_term();
		fts_reset_signal(0);
		ioctl(0, TIOCSTI, "\032");
	}
	if (g_fts.sig_t == 2)
	{
		fts_init_signal();
		fts_set_term();
		fts_cap("vi");
	}
}
