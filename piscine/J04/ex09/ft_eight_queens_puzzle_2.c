/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 17:50:32 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/11 01:31:56 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_dame(int *dame)
{
	int i;

	i = 0;
	while (i < 8)
	{
		ft_putchar(48 + dame[i]);
		i++;
	}
	ft_putchar('\n');
}

void	transpose(int *a, int *b)
{
	int i;

	i = 0;
	while (i < 8)
	{
		a[i] = b[i];
		i++;
	}
}

int		possible_dame(int position, int i, int *dame)
{
	int interdit[3];
	int i2;

	i2 = 0;
	while (i2 < position)
	{
		interdit[0] = dame[i2];
		interdit[1] = dame[i2] + (position - (i2 + 1));
		interdit[2] = dame[i2] - (position - (i2 + 1));
		if (i != interdit[0] && i != interdit[1] && i != interdit[2])
		{
			if (i2 + 1 == position)
				return (1);
			else
				i2++;
		}
		else
			return (0);
	}
	return (0);
}

void	countdame(int position, int *dame)
{
	int i;
	int tmpdame[8];
	int count;

	count = 0;
	transpose(tmpdame, dame);
	i = 1;
	while (i <= 8)
	{
		if (possible_dame(position, i, tmpdame))
		{
			tmpdame[position - 1] = i;
			if (position == 8)
			{
				print_dame(tmpdame);
			}
			else
				countdame(position + 1, tmpdame);
		}
		i++;
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	int damel[8];
	int i;

	i = 0;
	while (i != 8)
	{
		damel[i] = 0;
		i++;
	}
	countdame(1, damel);
}
