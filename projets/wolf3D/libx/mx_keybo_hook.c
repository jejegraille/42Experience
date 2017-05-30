/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_keybo_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:42:31 by jgraille          #+#    #+#             */
/*   Updated: 2017/05/27 16:17:46 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libx.h>
#include <libft.h>

static void		add_key(t_keybo *keybo, int key)
{
	t_key_l		*start;
	t_key_l		*elem;
	t_key_l		**list;

	list = &(keybo->down);
	elem = (t_key_l*)ft_memalloc(sizeof(t_key_l));
	elem->key = key;
	elem->next = NULL;
	start = *list;
	keybo->keycount += 1;
	if (start == NULL)
		*list = elem;
	else
	{
		while (start->next != NULL && start->key != key)
			start = start->next;
		if (start->key == key)
		{
			ft_memdel((void **)&elem);
			keybo->keycount -= 1;
		}
		else
			start->next = elem;
	}
}

static void		del_key(t_keybo *keybo, int key)
{
	t_key_l		*start;
	t_key_l		*last;
	t_key_l		**list;

	list = &(keybo->down);
	start = *list;
	if (start != NULL)
	{
		last = NULL;
		while (start != NULL && start->key != key)
		{
			last = start;
			start = start->next;
		}
		if (start != NULL && start->key == key)
		{
			if (last == NULL)
				*list = NULL;
			else
				last->next = start->next;
			ft_memdel((void **)&(start));
			keybo->keycount -= 1;
		}
	}
}

int				mx_key_down(int key)
{
	t_keybo		*keybo;
	t_key_l		*list;
	int			ret;
	int			i;

	keybo = get_keybo(NULL);
	list = keybo->down;
	ret = 0;
	i = 0;
	while (list != NULL)
	{
		i++;
		if (list->key == key)
			ret = 1;
		list = list->next;
	}
	return (ret);
}

int				mx_hook_k(int key, void *param)
{
	t_keybo *keybo;

	keybo = (t_keybo*)param;
	add_key(keybo, key);
	return (0);
}

int				mx_keybo_release(int key, void *param)
{
	t_keybo *kb;

	kb = (t_keybo *)param;
	kb->key = key;
	kb->onkey = 1;
	del_key(kb, key);
	return (0);
}
