/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:03:08 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/17 13:03:37 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_tube		*ft_create_link(t_room *ptr)
{
	t_tube		*new;

	if (!(new = (t_tube*)malloc(sizeof(t_tube))))
		return (NULL);
	new->link = ptr;
	new->link->status = new->link->status | NEXT;
	new->next = NULL;
	return (new);
}
