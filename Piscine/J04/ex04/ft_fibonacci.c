/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 01:09:09 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/10 04:00:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	long nb2;

	if (index > 3)
	{
		nb2 = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		if (nb2 <= 2147483647)
			return (nb2);
		else
			return (0);
	}
	else if (index > 2)
		return (2);
	else if (index > 0)
		return (1);
	else if (index == 0)
		return (0);
	else
		return (-1);
}
