/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:33:54 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/24 02:02:06 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int checker[2];

	i = -1;
	checker[0] = 0;
	checker[1] = 0;
	while (++i < length - 1)
		checker[0] += f(tab[i], tab[i + 1]) <= 0 ? 0 : 1;
	i = -1;
	while (++i < length - 1)
		checker[1] += f(tab[i], tab[i + 1]) >= 0 ? 0 : 1;
	return ((checker[0] == 0 || checker[1] == 0) ? 1 : 0);
}
