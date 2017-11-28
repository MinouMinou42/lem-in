/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:03:45 by nolivier          #+#    #+#             */
/*   Updated: 2016/11/25 15:13:06 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}
