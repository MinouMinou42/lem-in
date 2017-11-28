/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:39:47 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/17 11:45:45 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void		ft_del_anthill(t_room *anthill)
{
	t_room		*tmp;
	t_tube		*ptr;
	t_tube		*ptr2;

	while (anthill)
	{
		if (anthill->name)
			free(anthill->name);
		ptr = anthill->tube;
		while (ptr)
		{
			ptr2 = ptr;
			ptr = ptr->next;
			free(ptr2);
		}
		tmp = anthill;
		anthill = anthill->next;
		free(tmp);
	}
}
