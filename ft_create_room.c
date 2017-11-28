/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 10:43:27 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/11 13:08:44 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_room	*ft_create_room(t_room **anthill, int status)
{
	t_room	*tmp;

	if (*anthill == NULL)
	{
		if (!(*anthill = (t_room*)malloc(sizeof(t_room))))
			return (NULL);
		(*anthill)->status = status | ANTS;
		(*anthill)->name = NULL;
		tmp = *anthill;
	}
	else
	{
		tmp = *anthill;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_room*)malloc(sizeof(t_room))))
			return (NULL);
		tmp = tmp->next;
		tmp->status = status | ROOM;
	}
	tmp->tube = NULL;
	tmp->lem = 0;
	tmp->next = NULL;
	return (tmp);
}
