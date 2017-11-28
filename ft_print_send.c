/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_send.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:22:30 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/18 10:19:24 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_print_start_send(t_tube *ptr, int *lem, int ant_number,
		int *mem_move)
{
	if (!(*mem_move))
		*mem_move = 1;
	else
		ft_putchar(' ');
	*lem = ptr->next->link->lem;
	ptr->next->link->lem = ant_number;
	ft_print_lem_move(ptr->next->link->lem, ptr->next->link->name);
}

static void		ft_print_room_send(t_tube *ptr, int *lem, int *mem_move)
{
	int			tmp_lem;

	tmp_lem = *lem;
	*lem = ptr->next->link->lem;
	ptr->next->link->lem = tmp_lem;
	if (ptr->next->link->lem)
	{
		if (!(*mem_move))
			*mem_move = 1;
		else
			ft_putchar(' ');
		ft_print_lem_move(ptr->next->link->lem, ptr->next->link->name);
	}
}

static void		ft_print_way_send(t_way *tmp, int i, int *ant_number,
		int *mem_move)
{
	int			lem;
	t_tube		*ptr;

	ptr = tmp->way;
	while (ptr->next)
	{
		if (ptr == tmp->way)
		{
			if (i < tmp->ants)
			{
				ft_print_start_send(ptr, &lem, *ant_number, mem_move);
				*ant_number = *ant_number + 1;
			}
			else
			{
				lem = ptr->next->link->lem;
				ptr->next->link->lem = 0;
			}
		}
		else if (ptr->next->link->lem > 0 || lem > 0)
			ft_print_room_send(ptr, &lem, mem_move);
		ptr = ptr->next;
	}
}

void			ft_print_send(t_way *ways)
{
	int			i;
	int			turns;
	int			ant_number;
	int			mem_move;
	t_way		*tmp;

	i = 0;
	ant_number = 1;
	turns = ways->ants + ways->length - 1;
	while (i < turns)
	{
		mem_move = 0;
		tmp = ways;
		while (tmp)
		{
			ft_print_way_send(tmp, i, &ant_number, &mem_move);
			tmp = tmp->next;
		}
		ft_putchar('\n');
		i++;
	}
}
