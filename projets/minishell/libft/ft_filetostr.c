/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:10:23 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/29 17:55:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char		*ft_filetostr(char *filepath)
{
	char	buff[32];
	size_t	len;
	size_t	ret;
	int		ref;
	char	*str;

	ref = open(filepath, O_RDONLY);
	if (ref == -1)
		return (NULL);
	str = ft_strnew(0);
	len = 0;
	ret = 1;
	while (ret != 0)
	{
		ret = read(ref, buff, 32);
		str = (char *)ft_realloc((void *)&str, len + ret + 1);
		ft_memcpy((void *)(str + len), buff, ret);
		len += ret;
	}
	str[len] = '\0';
	close(ref);
	return (str);
}
