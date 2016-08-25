/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 23:19:07 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/17 21:59:52 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	long	grand[2];
	long	result;
	int		i;
	int		neg;

	result = 0;
	i = 0;
	while (0 <= str[i] && str[i] <= 32)
		i++;
	neg = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	grand[0] = 1;
	while (47 <= str[i] && str[i] <= 57 && str[i] != '\0')
	{
		i++;
		grand[0] = grand[0] * 10;
	}
	grand[1] = 1;
	while (grand[1] < grand[0] && str[--i])
	{
		result = result + (grand[1] * (str[i] - 48));
		grand[1] = grand[1] * 10;
	}
	return (result * neg);
}
