/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:06:42 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/18 10:05:28 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static void		ft_copy_way(t_tube *ptr, t_tube **ptr2)
{
	while (ptr)
	{
		if (!((*ptr2)->next = ft_create_link(ptr->link)))
			return ;
		(*ptr2) = (*ptr2)->next;
		(*ptr2)->link = ptr->link;
		ptr = ptr->next;
	}
}

static void		ft_create_new_way(t_room *room, t_way *list)
{
	t_way		*p;
	t_tube		*ptr;
	t_tube		*ptr2;

	p = list;
	while (p->next)
		p = p->next;
	if (!(p->next = (t_way*)malloc(sizeof(t_way))))
		return ;
	p = p->next;
	if (!(p->way = (t_tube*)malloc(sizeof(t_tube))))
		return ;
	ptr2 = p->way;
	ptr = list->way->next;
	ptr2->link = list->way->link;
	ft_copy_way(ptr, &ptr2);
	if (!(ptr2->next = ft_create_link(room)))
		return ;
	p->next = NULL;
}

static void		ft_del_first_way(t_way **list)
{
	t_way		*tmp;

	if (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		ft_free_way(tmp);
	}
}

int				ft_search_end(t_way **list, t_way *end)
{
	t_tube		*ptr;
	t_tube		*ptr2;
	t_way		*p;

	p = *list;
	while (p && p != end->next)
	{
		ptr = p->way;
		while (ptr->next && (ptr->next->link->status & CURRENT))
			ptr = ptr->next;
		ptr2 = ptr->link->tube;
		while (ptr2)
		{
			if (!(ptr2->link->status & (CURRENT + USED)))
			{
				ft_create_new_way(ptr2->link, p);
				if (ptr2->link->status & END)
					return (1);
			}
			ptr2 = ptr2->next;
		}
		p = p->next;
		ft_del_first_way(list);
	}
	return (0);
}
