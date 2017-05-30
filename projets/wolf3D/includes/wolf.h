/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:57:05 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/30 13:31:57 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

typedef struct		s_map
{
	int		width;
	int		height;
	int		depth;
	int		len;
	char	*data;
}					t_map;

t_map				*init_map(int width, int height, int depth);
t_map				*get_map(t_map *save);

#endif
