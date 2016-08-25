/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 18:56:55 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/11 20:09:23 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	char	mark;
	char	mark2;
	int		hour2;

	mark = 'P';
	mark2 = 'P';
	hour2 = hour + 1;
	hour2 = (hour2 == 24) ? 0 : hour2;
	if (0 <= hour && hour <= 11)
	{
		mark = 'A';
		hour = (hour == 0) ? 12 : hour;
	}
	else if (hour > 12)
		hour = hour - 12;
	if (0 <= hour2 && hour2 <= 11)
	{
		mark2 = 'A';
		hour2 = (hour2 == 0) ? 12 : hour2;
	}
	else if (hour2 > 12)
		hour2 = hour2 - 12;
	printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %c.M AND %d.00 %c.M.\n",
	hour, mark, hour2, mark2);
}
