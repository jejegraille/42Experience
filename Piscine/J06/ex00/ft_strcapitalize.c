/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 05:39:29 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/15 17:46:21 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		type(char c)
{
	int ok;

	ok = 0;
	ok += ((48 <= c && c <= 57) ? 1 : 0);
	ok += ((65 <= c && c <= 90) ? 2 : 0);
	ok += ((97 <= c && c <= 122) ? 3 : 0);
	return (ok);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int maj;

	i = 0;
	while (str[i] != '\0')
	{
		if (type(str[i - 1]) == 0 && type(str[i]) == 3)
			str[i] = str[i] - 32;
		if (type(str[i - 1]) != 0 && type(str[i]) == 2)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
