/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 05:34:28 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/18 03:25:48 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int i2;

	i2 = 0;
	i = 0;
	while (dest[i2] != '\0')
		i2++;
	if (i2 <= size)
	{
		while (src[i] != '\0' && i < size)
		{
			dest[i2 + i] = src[i];
			i++;
		}
		i = 0;
	}
	while (src[i] != '\0')
		i++;
	return (size < i2 ? size + i : (i + i2));
}
