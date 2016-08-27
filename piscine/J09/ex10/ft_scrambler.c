/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 05:09:23 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/12 05:24:03 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int t[4];

	t[0] = ***a;
	t[1] = *b;
	t[2] = ******c;
	t[3] = ****d;
	******c = t[0];
	****d = t[2];
	*b = t[3];
	***a = t[1];
}