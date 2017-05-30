/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:57:02 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/16 13:01:02 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static	void		put_hex(unsigned int oct)
{
	char			*base_hex;
	char			hex[2];
	unsigned int	c;

	c = oct;
	base_hex = "0123456789abcdef";
	hex[0] = base_hex[(c / 16) % 16];
	hex[1] = base_hex[c % 16];
	write(1, hex, 2);
}

static void			print_num(const void *addr, size_t len)
{
	size_t	i;
	char	*mem;

	mem = (char *)addr;
	i = 0;
	while (i < 16)
	{
		if (i >= len)
			write(1, "  ", 2);
		else
			put_hex((unsigned int)(mem[i]));
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

static void			print_str(const void *addr, size_t len)
{
	size_t	i;
	char	*mem;
	char	c;

	mem = (char *)addr;
	i = 0;
	while (i < 16 && i < len)
	{
		c = mem[i];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void				ft_put_memory(const void *addr, size_t size)
{
	size_t	i;

	i = 0;
	if (addr != NULL)
	{
		while (i / 16 <= size / 16)
		{
			print_num(addr + i, size - i);
			print_str(addr + i, size - i);
			i += 16;
		}
	}
}
