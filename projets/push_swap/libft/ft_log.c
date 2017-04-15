/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 14:36:07 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/01 15:16:58 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

void	ft_log(char *str, char *separator)
{
	static int fd;

	if (fd == 0)
		fd = open("./.logtmp", O_CREAT | O_RDWR | O_TRUNC);
	ft_putstr_fd(str, fd);
	if (separator != NULL)
		ft_putstr_fd(separator, fd);
}
