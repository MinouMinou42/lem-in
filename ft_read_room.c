/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 10:58:25 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/20 15:24:22 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static int		ft_read_coordroom(char **line, int *coord)
{
	if (!ft_isspace(**line))
		return (-1);
	else
		*line += 1;
	if (ft_isdigit(**line) ||
			((**line == '+' || **line == '-') && ft_isdigit(*(*line + 1))))
		*coord = ft_atoi(*line);
	else
		return (-1);
	if (**line == '+' || **line == '-')
		*line += 1;
	while (ft_isdigit(**line))
		*line += 1;
	return (1);
}

int				ft_read_room(t_input **current, char *line,
		t_room **tmp, int status)
{
	int		i;

	if (*line == 'L')
		return (-1);
	*current = ft_create_data(current, line);
	i = 0;
	while (ft_isspace(line[i]) == 0 && line[i])
		i++;
	*tmp = ft_create_room(tmp, status);
	if (!((*tmp)->name = (char*)malloc(sizeof(char) * (i + 1))))
		return (-1);
	(*tmp)->name = ft_strncpy((*tmp)->name, line, i);
	(*tmp)->name[i] = '\0';
	line += i;
	if (ft_read_coordroom(&line, &(*tmp)->x) < 1)
		return (-1);
	if (ft_read_coordroom(&line, &(*tmp)->y) < 1)
		return (-1);
	return (*line ? -1 : 1);
}
