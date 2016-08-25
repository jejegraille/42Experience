/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 00:07:04 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/17 00:31:41 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_arg(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		ft_putchar(argv[i]);
		i++;
	}
	ft_putchar('\n');
}

int		is_min(char *a, char *b)
{
	int		i;

	i = 0;
	while (a[i] == b[i] && a[i + 1] != '\0' && b[i + 1] != '\0')
		i++;
	return (a[i] - b[i]);
}

int		main(int argc, char **argv)
{
	char	*tmp;
	int		pos_arg;
	int		i;
	int		i2;

	i = 1;
	i2 = 1;
	while (i < argc)
	{
		pos_arg = 1;
		tmp = argv[1];
		while (i2 < argc)
		{
			if (argv[i2][0] != '~' && is_min(tmp, argv[i2]) >= 0)
			{
				tmp = argv[i2];
				pos_arg = i2;
			}
			i2++;
		}
		i2 = 1;
		print_arg(argv[pos_arg]);
		argv[pos_arg][0] = '~';
		i++;
	}
}
