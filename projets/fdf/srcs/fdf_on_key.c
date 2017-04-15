/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_on_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:58:15 by jgraille          #+#    #+#             */
/*   Updated: 2017/02/15 17:50:58 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		fdf_on_key(int key, void *control)
{
	t_ctrl *ctrl;

	ctrl = (t_ctrl *)control;
	ctrl->last_key = key;
	ctrl->key_time = 0.5;
	return (1);
}
