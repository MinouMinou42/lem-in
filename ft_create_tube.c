/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:27:21 by nolivier          #+#    #+#             */
/*   Updated: 2017/04/06 11:25:42 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void		ft_create_tube(t_room *r1, t_room *r2)
{
	t_tube		*current;
	t_tube		*prev;

	if (r1->tube == NULL)
	{
		if (!(r1->tube = (t_tube*)malloc(sizeof(t_tube))))
			return ;
		r1->tube->link = r2;
		r1->tube->next = NULL;
	}
	else
	{
		current = r1->tube;
		while (current)
		{
			if (current->link == r2)
				return ;
			prev = current;
			current = current->next;
		}
		if (!(prev->next = (t_tube*)malloc(sizeof(t_tube))))
			return ;
		prev->next->link = r2;
		prev->next->next = NULL;
	}
}
