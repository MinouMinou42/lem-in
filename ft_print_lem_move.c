/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lem_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:21:12 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/17 13:21:51 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_print_lem_move(int lem, char *name)
{
	ft_putchar('L');
	ft_putnbr(lem);
	ft_putchar('-');
	ft_putstr(name);
}
