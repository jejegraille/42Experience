/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:06:04 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/24 10:32:27 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <libft.h>
#include <unistd.h>

t_mx	*mx_init(int width, int height, char *title)
{
	t_mx	*new;
	t_image	ca;

	new = get_mx(NULL);
	new->id = mlx_init();
	new->init = 1;
	new->win = mlx_new_window(new->id, width, height, title);
	new->height = height;
	new->width = width;
	ca = get_mlx_image(width, height);
	new->canvas = ca;
	return (new);
}
