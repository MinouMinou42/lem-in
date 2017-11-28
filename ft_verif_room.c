/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:09:32 by nolivier          #+#    #+#             */
/*   Updated: 2017/04/06 13:10:50 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_verif_room(t_room *tmp, t_room *anthill)
{
	while (anthill)
	{
		if (anthill->name && tmp->name)
		{
			if (!ft_strcmp(tmp->name, anthill->name) && tmp != anthill)
				return (-1);
		}
		anthill = anthill->next;
	}
	return (1);
}
