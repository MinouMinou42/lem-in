/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_shortest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:01:26 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/18 10:06:36 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static t_way	*ft_init_way(t_room *tmp)
{
	t_way		*new;

	while (tmp && !(tmp->status & START))
		tmp = tmp->next;
	if (!(new = (t_way*)malloc(sizeof(t_way))))
		return (NULL);
	new->way = ft_create_link(tmp);
	new->next = NULL;
	new->way->link->status = new->way->link->status | CURRENT;
	return (new);
}

static void		ft_lock_room(t_room *anthill)
{
	while (anthill)
	{
		if (anthill->status & CURRENT)
			anthill->status = anthill->status | LOCKED;
		if (anthill->status & NEXT)
			anthill->status = anthill->status | CURRENT;
		anthill = anthill->next;
	}
}

static int		ft_current_room(t_room *anthill)
{
	while (anthill)
	{
		if ((anthill->status & CURRENT) && !(anthill->status & LOCKED))
			return (1);
		anthill = anthill->next;
	}
	return (0);
}

static t_way	*ft_select_way(t_way *list)
{
	t_way		*end;
	t_way		*p;

	end = list;
	while (end->next)
		end = end->next;
	p = list;
	while (p)
	{
		if (p != end)
			ft_free_way(p);
		p = list->next;
		list = list->next;
	}
	return (end);
}

t_way			*ft_seek_shortest(t_room *anthill)
{
	t_way		*list;
	t_way		*end;

	if (!(list = ft_init_way(anthill->next)))
		return (NULL);
	while (ft_current_room(anthill->next))
	{
		end = list;
		while (end->next)
			end = end->next;
		if (ft_search_end(&list, end))
			return (ft_select_way(list));
		ft_lock_room(anthill->next);
	}
	ft_del_ways(list);
	return (NULL);
}
