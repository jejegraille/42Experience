/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 03:44:55 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/13 04:03:21 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int i;
	int ret;

	i = 0;
	while ((65 <= str[i] && str[i] <= 90) || (97 <= str[i] && str[i] <= 122))
	{
		i++;
	}
	if (str == 0)
		ret = 1;
	else if (str[i] == '\0')
		ret = 1;
	else
		ret = 0;
	return (ret);
}
