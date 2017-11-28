/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:23:43 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/17 11:39:08 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void		ft_del_input(t_input *data)
{
	t_input		*tmp;

	while (data)
	{
		if (data->str)
			free(data->str);
		tmp = data;
		data = data->next;
		free(tmp);
	}
}
