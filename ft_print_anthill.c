/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_anthill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:11:25 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/16 13:20:27 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_print_room(char *name, int x, int y)
{
	ft_putstr("==> |");
	if (!name)
		ft_putstr("null");
	else
		ft_putstr(name);
	ft_putstr("| (");
	ft_putnbr(x);
	ft_putstr(", ");
	ft_putnbr(y);
	ft_putstr(")");
}

static void		ft_print_tube(char *name)
{
	ft_putstr(" ->|");
	ft_putstr(name);
	ft_putstr("|");
}

void			ft_print_anthill(t_room *anthill)
{
	t_tube		*ptr;

	while (anthill)
	{
		ft_print_room(anthill->name, anthill->x, anthill->y);
		if (anthill->status & START)
			ft_putstr(" ##start");
		if (anthill->status & END)
			ft_putstr(" ##end");
		ptr = anthill->tube;
		while (ptr)
		{
			ft_print_tube(ptr->link->name);
			ptr = ptr->next;
		}
		ft_putchar('\n');
		anthill = anthill->next;
	}
}
