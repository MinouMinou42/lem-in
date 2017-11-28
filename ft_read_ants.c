/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 10:47:42 by nolivier          #+#    #+#             */
/*   Updated: 2017/04/05 11:06:31 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_read_ants(t_input **data, t_input **current,
		char *line, t_room **anthill)
{
	int		nb;

	if (*data == NULL)
	{
		*data = ft_create_data(data, line);
		*current = *data;
	}
	else
		*current = ft_create_data(data, line);
	if ((nb = ft_atoi(line)) > 0)
	{
		*anthill = ft_create_room(anthill, 0);
		(*anthill)->x = nb;
	}
	else
		return (-1);
	if (*line == '+' || *line == '-')
		line++;
	while (*line >= '0' && *line <= '9')
		line++;
	return (*line ? -1 : 1);
}
