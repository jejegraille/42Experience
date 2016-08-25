/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 23:19:07 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/15 19:40:01 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	long	grand[2];
	int		result;
	int		i;
	int		neg;

	grand[0] = 1;
	grand[1] = 1;
	result = 0;
	i = 0;
	while (0 <= str[i] && str[i] <= 32)
		i++;
	neg = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (47 <= str[i] && str[i] <= 57)
	{
		i++;
		grand[0] = grand[0] * 10;
	}
	while (grand[1] < grand[0])
	{
		i--;
		result = result + (grand[1] * (str[i] - 48));
		grand[1] = grand[1] * 10;
	}
	return (result * neg);
}
