/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rgba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:41:37 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/17 15:43:04 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>

t_rgba		get_rgba(int r, int g, int b, int a)
{
	t_rgba rgba;

	rgba.r = r;
	rgba.g = g;
	rgba.b = b;
	rgba.a = a;
	return (rgba);
}
