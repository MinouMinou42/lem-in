/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 10:52:28 by nolivier          #+#    #+#             */
/*   Updated: 2017/04/04 11:39:44 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_istube(char *line)
{
	int		dash;

	dash = 0;
	if (*line == '#')
		return (0);
	while (ft_isspace(*line) == 0 && *line)
	{
		if (*line == '-')
		{
			if (dash)
				return (0);
			else
				dash = 1;
		}
		line++;
	}
	if (*line == '\0' && dash == 1)
		return (1);
	return (0);
}
