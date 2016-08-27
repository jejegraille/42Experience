/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 21:53:29 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/15 21:57:42 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	char	*arg;
	int		i;
	int		i2;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		i2 = 0;
		while (arg[i2] != '\0')
		{
			ft_putchar(arg[i2]);
			i2++;
		}
		ft_putchar('\n');
		i++;
	}
}
