/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 02:08:53 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/12 02:43:50 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	int count;

	count = 0;
	if (base % 2 == 0)
	{
		count++;
		count = count + ft_collatz_conjecture(base / 2);
	}
	else if (base != 1)
	{
		count++;
		count = count + ft_collatz_conjecture((base * 3) + 1);
	}
	return (count);
}
