/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 22:33:47 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/22 23:42:31 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcomp(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	if (a[i] || b[i])
		return (a[i] - b[i]);
	else
		return (0);
}

void	ft_sort_wordtab(char **tab)
{
	int		i;
	char	*tmp;

	i = -1;
	while (tab[++i + 1])
		if (ft_strcomp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
}
