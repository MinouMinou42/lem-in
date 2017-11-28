/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:53:55 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/18 15:26:10 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "lemin.h"

static char		*ft_read(int fd, int *ret)
{
	char			buf[BUFF_SIZE + 1];

	*ret = read(fd, buf, BUFF_SIZE);
	buf[*ret] = '\0';
	return ((buf[0] == '\0') ? NULL : ft_strdup(buf));
}

static char		*ft_join(char *s1, char *s2)
{
	char			*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

static int		ft_manage(t_rest *elem, char **line)
{
	int				ret;
	char			*tmp;
	char			*str;

	ret = 1;
	str = (elem->rest) ? elem->rest : ft_read(elem->fd, &ret);
	if (ret <= 0)
		return (ret);
	*line = ft_strdup("\0");
	while (ret > 0)
	{
		if ((tmp = ft_strchr(str, '\n')))
		{
			*tmp = '\0';
			elem->rest = ft_strdup(tmp + 1);
			*line = ft_join(*line, str);
			return (1);
		}
		*line = ft_join(*line, str);
		str = ft_read(elem->fd, &ret);
	}
	elem->rest = NULL;
	return ((ft_strlen(*line)) ? 1 : ret);
}

static t_rest	*ft_create_fd(int fd)
{
	t_rest			*new;

	if (!(new = (t_rest*)malloc(sizeof(t_rest))))
		return (NULL);
	new->fd = fd;
	new->rest = NULL;
	new->next = NULL;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_rest	*data = NULL;
	t_rest			*elem;
	int				ret;

	if (BUFF_SIZE < 1 || line == NULL || fd < 0)
		return (-1);
	if (data)
	{
		elem = data;
		while (fd != elem->fd && elem->next)
			elem = elem->next;
		if (fd != elem->fd)
		{
			elem->next = ft_create_fd(fd);
			elem = elem->next;
		}
	}
	else
	{
		data = ft_create_fd(fd);
		elem = data;
	}
	ret = ft_manage(elem, line);
	return (ret);
}
