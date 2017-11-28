/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 11:32:12 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/20 12:35:22 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

int		ft_free_error(char *line, t_input *current)
{
	while (current->next)
		current = current->next;
	if (line && line != current->str)
		free(line);
	return (1);
}
