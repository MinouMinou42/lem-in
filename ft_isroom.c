/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isroom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:16:45 by nolivier          #+#    #+#             */
/*   Updated: 2017/04/06 11:28:56 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_isroom(char *line)
{
	if (*line == '#')
		return (0);
	while (ft_isspace(*line) == 0 && *line && *line != '-')
	{
		line++;
	}
	if (*line == ' ')
		line++;
	else
		return (0);
	if (*line == '+' || *line == '-')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (*line == ' ')
		line++;
	else
		return (0);
	if (*line == '+' || *line == '-')
		line++;
	while (ft_isdigit(*line))
		line++;
	return (*line ? 0 : 1);
}
