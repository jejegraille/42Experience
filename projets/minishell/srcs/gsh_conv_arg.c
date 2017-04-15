/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsh_conv_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:49:17 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/14 15:33:40 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsh.h>

static void			conv_str(char *str)
{
	int		conv;
	size_t	i;

	conv = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (i == 0 || str[i - 1] != '\\'))
			str[i] = str[i];
		if (conv && str[i] == ' ')
			str[i] = -1;
		if (conv && str[i] == '	')
			str[i] = -2;
		if (str[i] == '"')
			conv = conv ? 0 : 1;
		i++;
	}
}

static void			rev_str(char **str)
{
	char	*new;
	size_t	i;
	size_t	i2;

	new = ft_strnew(ft_strlen(*str));
	i = 0;
	i2 = 0;
	while ((*str)[i2])
	{
		if ((*str)[i2] == '\\')
			i2++;
		while ((*str)[i2] == '"' && (i2 == 0 || (*str)[i2 - 1] != '\\'))
			i2++;
		new[i] = (*str)[i2];
		if ((*str)[i2] == -1)
			new[i] = ' ';
		if ((*str)[i2] == -2)
			new[i] = '	';
		i++;
		i2++;
	}
	ft_memdel((void **)str);
	*str = new;
}

char				**conv_arg(t_gsh *data, char *str)
{
	char	**arg;
	int		i;

	(void)data;
	conv_str(str);
	arg = ft_split_c(str, " 	");
	i = -1;
	while (arg[++i])
		rev_str(arg + i);
	return (arg);
}
