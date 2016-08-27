/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 05:33:10 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/20 05:39:29 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*make_a_line(int argc, char **argv)
{
	int		i;
	int		i2;
	int		size;

	i = 0;
	i2 = 0;
	size = 0;
	while (i < argc - 1)
	{
		i++;
		while (argv[i][i2] != '\0')
		{
			i2++;
			size++;
		}
		size++;
		i2 = 0;
	}
	return (malloc(sizeof(char) * size));
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*chaine;
	int		i;
	int		i2;
	int		i3;

	if (argc > 1)
	{
		chaine = make_a_line(argc, argv);
		i = 0;
		i3 = 0;
		while (i++ < argc - 1)
		{
			i2 = 0;
			while (argv[i][i2] != '\0')
			{
				chaine[i3] = argv[i][i2];
				i2++;
				i3++;
			}
			chaine[i3] = (i != argc - 1) ? '\n' : '\0';
			i3++;
		}
		return (chaine);
	}
	return ("");
}
