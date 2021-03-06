/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 23:19:07 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/20 17:20:59 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		result;
	int		i;
	int		neg;

	result = 0;
	i = 0;
	while (0 <= str[i] && str[i] <= 32)
		i++;
	neg = (str[i] == '-') ? -1 : 1;
	i += (str[i] == '-' || str[i] == '+') ? 1 : 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * neg);
}
