/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 21:46:02 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/16 23:22:49 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	char	*file_name;
	int		i;

	if (argc != 0)
	{
		file_name = argv[0];
		i = 0;
		while (file_name[i])
		{
			ft_putchar(file_name[i]);
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
