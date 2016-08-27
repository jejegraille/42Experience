/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 08:16:20 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/15 08:54:06 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_hex(int nb)
{
	char back[2];

	if (nb < 16)
		back[0] = '0';
	else
		back[0] = '1';
	if (0 <= nb % 16 && nb % 16 <= 9)
		back[1] = 'a' + (nb % 16);
	else
		back[1] = 'a' + (nb % 16) - 10;
	ft_putchar('\\');
	ft_putchar(back[0]);
	ft_putchar(back[1]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 31)
			ft_putchar(str[i]);
		else
			print_hex(str[i]);
		i++;
	}
}
