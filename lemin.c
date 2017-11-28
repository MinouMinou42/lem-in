/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:31:00 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/24 12:47:46 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_error(void)
{
	ft_putstr("ERROR\n");
	return (0);
}

static void		ft_print_input(t_input *data)
{
	while (data)
	{
		ft_putstr(data->str);
		ft_putchar('\n');
		data = data->next;
	}
	ft_putchar('\n');
}

static int		ft_start_is_end(t_room *anthill)
{
	while (anthill && !(anthill->status & START))
		anthill = anthill->next;
	return ((anthill && (anthill->status & END)) ? 1 : 0);
}

static int		ft_lemin(t_input **data, t_room **anthill, t_way **ways)
{
	*anthill = NULL;
	*data = NULL;
	if (ft_purchase(data, anthill) < 1)
		return (-1);
	if (ft_start_is_end(*anthill))
	{
		ft_print_input(*data);
		return (1);
	}
	if (!(*ways = ft_find_way(*anthill)))
		return (-1);
	ft_print_input(*data);
	ft_send_ants((*anthill)->x, *ways);
	ft_del_ways(*ways);
	return (1);
}

int				main(void)
{
	t_room	*anthill;
	t_input	*data;
	t_way	*ways;

	if (ft_lemin(&data, &anthill, &ways) < 1)
	{
		ft_del_input(data);
		ft_del_anthill(anthill);
		return (ft_error());
	}
	ft_del_input(data);
	ft_del_anthill(anthill);
	return (1);
}
