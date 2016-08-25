/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:08:49 by jgraille          #+#    #+#             */
/*   Updated: 2016/08/12 11:40:10 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PERSO_H
# define FT_PERSO_H

enum SAVE_AUSTIN_POWERS;

Typedef 		s_perso
{
	int age;
	float life;
	int profession;
	char *name;
}					t_perso;

char *strdup(char *str)
{
	return (str);
}
#endif
