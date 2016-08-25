/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:48:51 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/08 20:49:08 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrev(char *str)
{
	int		i;
	int		count;
	char	tmp;

	count = 0;
	if (str)
	{
		i = 0;
		while (str[count] != '\0')
		{
			count++;
		}
		count = count - 1;
		while (i <= count / 2)
		{
			tmp = str[i];
			str[i] = str[count - i];
			str[count - i] = tmp;
			i++;
		}
	}
	return (str);
}
