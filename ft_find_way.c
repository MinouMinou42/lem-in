/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:32:05 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/20 14:47:49 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_links_count(t_room *anthill)
{
	int		count;
	t_tube	*tmp;

	count = 0;
	tmp = anthill->tube;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static int		ft_seek_way(t_room *anthill)
{
	int		start_links;
	int		end_links;

	start_links = 0;
	end_links = 0;
	while (anthill)
	{
		if (anthill->status & START)
			start_links = ft_links_count(anthill);
		if (anthill->status & END)
			end_links = ft_links_count(anthill);
		anthill = anthill->next;
	}
	return ((start_links > end_links) ? end_links : start_links);
}

static void		ft_lock_way(t_way *ways)
{
	t_tube	*ptr;

	ptr = ways->way;
	while (ptr)
	{
		if (!(ptr->link->status & (START + END)))
			ptr->link->status = ptr->link->status | USED;
		ptr = ptr->next;
	}
}

static void		ft_unlock_room(t_room *anthill)
{
	while (anthill)
	{
		anthill->status = anthill->status & ~(NEXT + CURRENT + LOCKED);
		anthill = anthill->next;
	}
}

t_way			*ft_find_way(t_room *anthill)
{
	t_way	*list;
	t_way	*ways;
	int		nb_ways;
	int		nb;

	if ((nb_ways = ft_seek_way(anthill)) == 0)
		return (NULL);
	if (anthill->x == 1 || nb_ways == 1)
		return (ft_seek_shortest(anthill));
	nb = 1;
	if (!(list = ft_seek_shortest(anthill)))
		return (NULL);
	ft_lock_way(list);
	ways = list;
	while (nb < nb_ways && nb < anthill->x && ways)
	{
		ft_unlock_room(anthill);
		ways->next = ft_seek_shortest(anthill);
		nb++;
		ways = ways->next;
		if (ways)
			ft_lock_way(ways);
	}
	return (list);
}
