/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_signal_fctn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:38:09 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/29 13:04:35 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <ft_select.h>
#include <sys/ioctl.h>

void	fts_sig_cc(int sig)
{
	char str[3];

	(void)sig;
	g_fts.sig_t = 0;
	str[0] = -10;
	str[1] = '\0';
	ioctl(0, TIOCSTI, str);
}

void	fts_sig_cz(int sig)
{
	char str[3];

	(void)sig;
	g_fts.sig_t = 1;
	str[0] = -10;
	str[1] = '\0';
	ioctl(0, TIOCSTI, str);
}

void	fts_sig_cnt(int sig)
{
	char str[3];

	(void)sig;
	g_fts.sig_t = 2;
	str[0] = -10;
	str[1] = '\0';
	ioctl(0, TIOCSTI, str);
}

void	fts_sig_win(int sig)
{
	char str[3];

	(void)sig;
	g_fts.sig_t = -1;
	str[0] = -10;
	str[1] = '\0';
	ioctl(0, TIOCSTI, str);
}
