/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purchase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 10:20:46 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/24 12:47:11 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static int		ft_ants_purchase(t_input **data,
		t_input **current, t_room **anthill)
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		status = 0;
		if (get_next_line(0, &line) < 1)
			return (-1);
		if (!*data)
		{
			ft_comment(data, line, &status);
			*current = *data;
		}
		else
			ft_comment(current, line, &status);
		if ((status & START) || (status & END))
			return (-1);
	}
	if (ft_read_ants(data, current, line, anthill) < 1)
		return (-1);
	return (1);
}

static int		ft_comroom_purchase(char **line,
		t_input **current, int *status, int *mem_status)
{
	int		tmp_status;

	*status = 0;
	tmp_status = COMMENT;
	while (tmp_status)
	{
		tmp_status = 0;
		get_next_line(0, line);
		ft_comment(current, *line, &tmp_status);
		if (((*mem_status & START) && (tmp_status & START))
				|| ((*mem_status & END) && (tmp_status & END)))
			return (-1);
		*status = *status | tmp_status;
		*mem_status = *mem_status | tmp_status;
	}
	return (1);
}

static int		ft_room_purchase(char **line,
		t_input **current, t_room **tmp, t_room **anthill)
{
	int		status;
	int		mem_status;

	mem_status = 0;
	status = ROOM;
	while (status & ROOM)
	{
		if (ft_comroom_purchase(line, current, &status, &mem_status) < 1)
			return (-1);
		if (ft_isroom(*line))
		{
			status = status | ROOM;
			if (ft_read_room(current, *line, tmp, status) < 1)
				return (-1);
			if (ft_verif_room(*tmp, *anthill) < 1)
				return (-1);
		}
	}
	return (((!(mem_status & START)) || (!(mem_status & END))) ? -1 : 1);
}

static int		ft_tube_purchase(char **line,
		t_input **current, t_room **anthill)
{
	int		status;

	status = TUBE;
	while (status & TUBE)
	{
		while (status)
		{
			status = 0;
			ft_comment(current, *line, &status);
			if ((status & START) || (status & END))
				return (-1);
			if (status)
				get_next_line(0, line);
		}
		if (ft_istube(*line))
		{
			status = status | TUBE;
			if (ft_read_tube(current, *line, anthill) < 1)
				return (-1);
			get_next_line(0, line);
		}
	}
	return (1);
}

int				ft_purchase(t_input **data, t_room **anthill)
{
	t_input	*current;
	t_room	*tmp;
	char	*line;

	if (ft_ants_purchase(data, &current, anthill) < 1)
		return (-1);
	tmp = *anthill;
	if (ft_room_purchase(&line, &current, &tmp, anthill) < 1)
		return (ft_free_error(line, current));
	if (ft_tube_purchase(&line, &current, anthill) < 1)
		return (ft_free_error(line, current));
	return (ft_free_error(line, current));
}
