/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 14:38:36 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/12 11:35:52 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <operator.h>

typedef struct			s_clst
{
	struct s_clst	*next;
	char			c;
}						t_clst;

typedef struct			s_born
{
	int		min;
	int		max;
}						t_born;

typedef struct			s_ps
{
	t_lst	**a;
	t_lst	**b;
	int		la;
	int		lb;
	int		max;
	int		min;
	int		step;
}						t_ps;

char					*brute_swap(t_lst **a, t_lst **b, int la);
char					*mind_swap(t_lst **a, t_lst **b, int la);
void					exec_algo(t_lst **a, t_lst **b, int la);
int						check_pertnt(t_ps ps, char act, char l_act, int i);
char					*str_act(char action);
void					ps_exec(t_ps *ps, char action);
void					add_clst(t_clst **start, char c);
char					*ps_search_act(t_ps *ps);

#endif
