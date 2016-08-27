/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 08:57:46 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/17 08:23:14 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_adrr(void *addr)
{
	int i;
	int loc;
	char c;

	i = 0;
	loc = (int)&addr;
	while (i < 16)
	{
		printf("%d", loc);
		i++;
	}
	ft_putchar(':');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;
	char c;
	char *a;

	i= 0;
	a = addr;
	while (i < size)
	{
		c = a[i];
		ft_putchar(c);
		if ((i % 16) == 0)
			ft_putchar('\n');
		i++;
	}
	return (0);
}

int main ()
{
	char a[]="oulala cest dur tout ca suite...";
	void *taupe;

	taupe = a;
//	ft_print_memory(taupe, 32);
	print_adrr(taupe);
}
