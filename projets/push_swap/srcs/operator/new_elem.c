/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:05:59 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/02 19:12:20 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operator.h>
#include <libft.h>

static int	not_nbr(char *n, char **serror)
{
	int		i;
	int		no_nbr;

	no_nbr = 0;
	i = -1;
	while (no_nbr == 0 && n[++i])
	{
		if (!(ft_isdigit(n[i]) || (i == 0 && (n[i] == '-' || n[i] == '+'))))
		{
			no_nbr = 1;
			*serror = "Error : not a number";
		}
	}
	return (no_nbr);
}

t_lst		*new_elem(char *nb, char **serror)
{
	t_lst	*new;
	long	nbr;
	int		err;

	err = 0;
	err = not_nbr(nb, serror);
	if (err == 0)
		nbr = ft_atol(nb);
	if (!err && (nbr > 2147483647 || nbr < -2147483648))
	{
		*serror = "Error : nbr is not an integer";
		err = 1;
	}
	if (err)
		return (NULL);
	new = (t_lst *)ft_memalloc(sizeof(t_lst));
	new->nb = (int)nbr;
	new->next = NULL;
	new->back = NULL;
	return (new);
}
