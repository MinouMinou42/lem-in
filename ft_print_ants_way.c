/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ants_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:10:52 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/18 10:12:03 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_print_ants_way(t_way *ways)
{
	while (ways)
	{
		ft_putstr("Way lenght = ");
		ft_putnbr(ways->length);
		ft_putstr(" & ants = ");
		ft_putnbr(ways->ants);
		ft_putchar('\n');
		ways = ways->next;
	}
}
