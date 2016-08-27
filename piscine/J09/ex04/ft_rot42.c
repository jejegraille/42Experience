/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 00:19:15 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/12 01:49:14 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	replace42(char c)
{
	int type;
	int newc;

	type = 0;
	type = type + ((65 <= c && c <= 90) ? 1 : 0);
	type = type + ((97 <= c && c <= 122) ? 2 : 0);
	newc = c;
	if (type == 2)
	{
		newc = c + 16;
		newc = (newc > 122) ? newc - 122 + 97 : newc;
	}
	if (type == 1)
	{
		newc = c + 16;
		newc = (newc > 90) ? newc - 90 + 65 : newc;
	}
	c = newc;
	return (c);
}

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = replace42(str[i]);
		i++;
	}
	return (str);
}
