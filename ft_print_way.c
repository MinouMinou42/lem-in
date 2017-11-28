/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 12:58:00 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/16 15:27:46 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_way(t_way *ways)
{
	t_tube		*tmp;

	while (ways)
	{
		ft_putstr("Way : ");
		tmp = ways->way;
		while (tmp)
		{
			if (!(tmp->link->status & START))
				ft_putstr(" --> ");
			ft_putstr(tmp->link->name);
			tmp = tmp->next;
		}
		ft_putstr("\n");
		ways = ways->next;
	}
}
