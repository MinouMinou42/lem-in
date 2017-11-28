/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 10:31:02 by nolivier          #+#    #+#             */
/*   Updated: 2017/04/05 10:29:24 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_input		*ft_create_data(t_input **data, char *line)
{
	t_input		*tmp;

	if (*data)
	{
		tmp = *data;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_input*)malloc(sizeof(t_input))))
			return (NULL);
		tmp = tmp->next;
		tmp->str = line;
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		if (!(*data = (t_input*)malloc(sizeof(t_input))))
			return (NULL);
		(*data)->str = line;
		(*data)->next = NULL;
		return (*data);
	}
}
