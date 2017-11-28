/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:44:02 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/20 13:14:13 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static int		ft_read_linetube(char *line, char **str1, char **str2)
{
	int			i;

	i = 0;
	while (line[i] != '-')
	{
		i++;
	}
	if (!(*str1 = (char*)malloc(sizeof(char) * (i + 1))))
		return (-1);
	*str1 = ft_strncpy(*str1, line, i);
	(*str1)[i] = '\0';
	line += i + 1;
	i = ft_strlen(line);
	if (!(*str2 = (char*)malloc(sizeof(char) * (i + 1))))
	{
		free(str1);
		return (-1);
	}
	*str2 = ft_strncpy(*str2, line, i);
	(*str2)[i] = '\0';
	return (1);
}

static void		ft_read_roomtube(char *line,
		t_room **r1, t_room **r2, t_room *anthill)
{
	char		*str1;
	char		*str2;
	t_room		*tmp;

	if (ft_read_linetube(line, &str1, &str2) < 1)
		return ;
	tmp = anthill->next;
	while (tmp && (!*r1 || !*r2))
	{
		if (!ft_strcmp(str1, tmp->name))
			*r1 = tmp;
		if (!ft_strcmp(str2, tmp->name))
			*r2 = tmp;
		tmp = tmp->next;
	}
	free(str1);
	free(str2);
}

int				ft_read_tube(t_input **current, char *line, t_room **anthill)
{
	t_room		*r1;
	t_room		*r2;

	if (*line == 'L')
		return (-1);
	r1 = NULL;
	r2 = NULL;
	*current = ft_create_data(current, line);
	ft_read_roomtube(line, &r1, &r2, *anthill);
	if (!r1 || !r2)
		return (-1);
	else if (r1 == r2)
		return (1);
	ft_create_tube(r1, r2);
	ft_create_tube(r2, r1);
	return (1);
}
