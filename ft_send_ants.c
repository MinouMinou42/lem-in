/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 12:17:21 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/18 10:13:49 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			ft_set_length(t_way *ways)
{
	t_tube		*ptr;
	int			nb_ways;

	nb_ways = 0;
	while (ways)
	{
		ptr = ways->way;
		ways->length = 0;
		ways->ants = 0;
		while (ptr->next)
		{
			ways->length++;
			ptr = ptr->next;
		}
		nb_ways++;
		ways = ways->next;
	}
	return (nb_ways);
}

static void			ft_send_one_turn(int ants, t_way *ways)
{
	int			ant_number;
	int			mem_move;

	ant_number = 1;
	mem_move = 0;
	while (ant_number <= ants)
	{
		if (!mem_move)
			mem_move = 1;
		else
			ft_putchar(' ');
		ft_print_lem_move(ant_number, ways->way->next->link->name);
		ant_number++;
	}
	ft_putchar('\n');
}

void				ft_send_ants(int ants, t_way *ways)
{
	int			nb_ants;
	int			i;
	t_way		*tmp;

	ft_set_length(ways);
	if (ways->length == 1)
		return (ft_send_one_turn(ants, ways));
	nb_ants = ants;
	while (nb_ants)
	{
		i = ways->length + ways->ants;
		tmp = ways;
		while (tmp)
		{
			if (nb_ants > 0 && tmp->length <= i)
			{
				nb_ants--;
				tmp->ants++;
			}
			tmp = tmp->next;
		}
	}
	ft_print_send(ways);
}
