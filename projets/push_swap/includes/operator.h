/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:50:51 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/05 10:32:38 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include <stdlib.h>

typedef struct		s_lst
{
	int				nb;
	struct s_lst	*next;
	struct s_lst	*back;
}					t_lst;

typedef void		(*t_fct)(t_lst **, t_lst **);

void				sa(t_lst **a, t_lst **b);
void				sb(t_lst **a, t_lst **b);
void				ss(t_lst **a, t_lst **b);
void				pa(t_lst **a, t_lst **b);
void				pb(t_lst **a, t_lst **b);
void				ra(t_lst **a, t_lst **b);
void				rb(t_lst **a, t_lst **b);
void				rr(t_lst **a, t_lst **b);
void				rra(t_lst **a, t_lst **b);
void				rrb(t_lst **a, t_lst **b);
void				rrr(t_lst **a, t_lst **b);
t_lst				*new_elem(char *nb, char **serror);
void				add_elem(t_lst **start, t_lst *elem);
void				convert(t_lst **start, char **av, char **ser);
void				log_lst(t_lst *a, t_lst *b);
void				check_doublon(t_lst *a, char **serror);
int					check_order(t_lst *a, t_lst *b);
int					lst_count(t_lst *a);
#endif
