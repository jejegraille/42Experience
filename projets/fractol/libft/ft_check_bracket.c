/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bracket.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:06:27 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/16 13:06:50 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		is_bracket(char c)
{
	int	b;

	b = 0;
	c == '(' && (b = 1);
	c == ')' && (b = -1);
	c == '{' && (b = 2);
	c == '}' && (b = -2);
	c == '[' && (b = 3);
	c == ']' && (b = -3);
	c == '<' && (b = 4);
	c == '>' && (b = -4);
	return (b);
}

static int		brackets(char *line, int brac)
{
	int		bra;
	int		i;
	int		res;

	i = 0;
	while (line[i])
	{
		bra = is_bracket(line[i]);
		if (bra)
		{
			if (bra < 0)
				return ((brac + bra == 0) ? i + 1 : 0);
			if (bra > 0)
			{
				res = brackets(line + i + 1, bra);
				i += res;
				if (res == 0)
					return (0);
			}
		}
		i++;
	}
	return ((brac == 0));
}

int				ft_check_bracket(char *line)
{
	return (brackets(line, 0));
}
