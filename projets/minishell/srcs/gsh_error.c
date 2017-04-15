/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:41:04 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/26 16:32:26 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>
#include <libft.h>

void		gsh_error(t_gsh *data)
{
	if (data->error == 1)
	{
		ft_putstr_fd(data->cmd, 2);
		ft_putstr_fd(" : ", 2);
		ft_putstr_fd(data->serror, 2);
		ft_putstr_fd(data->serror2, 2);
		ft_putstr_fd("\n", 2);
	}
}
