/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 10:27:16 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/19 12:12:08 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_comment(t_input **data, char *line, int *status)
{
	t_input	*tmp;

	if (line[0] == '#')
	{
		tmp = ft_create_data(data, line);
		if (line[1] == '#')
		{
			if (!ft_strcmp(line + 2, "start"))
				*status = *status | START;
			else if (!ft_strcmp(line + 2, "end"))
				*status = *status | END;
		}
		*status = *status | COMMENT;
		*data = tmp;
	}
	return (1);
}
