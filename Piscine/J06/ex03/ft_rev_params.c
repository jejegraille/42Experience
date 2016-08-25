/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 22:10:15 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/15 22:12:33 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	char	*arg;
	int		i;
	int		i2;

	i = argc - 1;
	while (i > 0)
	{
		arg = argv[i];
		i2 = 0;
		while (arg[i2] != '\0')
		{
			ft_putchar(arg[i2]);
			i2++;
		}
		ft_putchar('\n');
		i--;
	}
}
