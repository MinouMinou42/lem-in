/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:33:11 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/17 10:37:44 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void		ft_free_way(t_way *current)
{
	t_tube		*ptr;
	t_tube		*ptr2;

	ptr = current->way;
	while (ptr)
	{
		ptr2 = ptr;
		ptr = ptr->next;
		free(ptr2);
	}
	free(current);
}
