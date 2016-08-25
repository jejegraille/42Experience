/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 22:23:12 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/11 03:29:50 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb <= 12)
	{
		if (nb - 1 > 0)
		{
			nb *= ft_recursive_factorial(nb - 1);
		}
		else if (nb <= 0)
			return (nb == 0 ? 1 : 0);
		else
			return (nb);
	}
	else
		return (0);
	return (nb);
}
