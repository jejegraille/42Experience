/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_mlx_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:46:11 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 14:45:25 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <string.h>

void			mx_mlx_image(t_image *ima)
{
	t_mx	*mx;

	if (ima != NULL)
	{
		mx = get_mx(NULL);
		mlx_put_image_to_window(mx->id, mx->win, ima->ptr, ima->x, ima->y);
	}
}
