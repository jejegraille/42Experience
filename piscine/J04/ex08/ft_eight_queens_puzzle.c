/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 20:00:47 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/10 19:24:45 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		countdame(int position, int *dame)
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
			count += ((position == 8) ? 1 : countdame(position + 1, tmpdame));
		}
		i++;
	}
	return (count);
}

int		ft_eight_queens_puzzle(void)
{
	int damel[8];
	int i;

	i = 0;
	while (i != 8)
	{
		damel[i] = 0;
		i++;
	}
	return (countdame(1, damel));
}
