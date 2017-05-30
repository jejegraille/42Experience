/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 12:47:28 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/28 13:15:30 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		usage_global(void)
{
	ft_putstr("__________________________________\n");
	ft_putstr("\x1B[32m[]        FRACTOL CONTROL       []\x1B[0m\n\n");
	ft_putstr("Directionnal key :	Move up/down/left/right\n");
	ft_putstr("Mouse weel :		Zoom  in/out\n");
	ft_putstr("key '+' :		More iteration\n");
	ft_putstr("key '-' :		Less iteration\n");
	ft_putstr("key 'T' :		Change coloration\n");
	ft_putstr("key 'N' :		Next capture\n");
	ft_putstr("key 'F' :		Next fractal\n");
	ft_putstr("SpaceBar :		Stop mouse modeling (Julia)\n");
	ft_putstr("Escape :		Exit fractal\n");
}

static void		usage_error(void)
{
	ft_putstr_fd("usage : ./fractole [-pick] fractale_name\n", 2);
	ft_putstr("1. mandelbrot\n");
	ft_putstr("2. julia\n");
	ft_putstr("3. burning_ship\n");
	ft_putstr("4. burning_bird\n");
	ft_putstr("5. rocket\n");
}

void			put_usage(int count)
{
	if (count == 0)
		usage_error();
	else
		usage_global();
}
