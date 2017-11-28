/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:05:33 by nolivier          #+#    #+#             */
/*   Updated: 2017/05/20 11:34:50 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define BUFF_SIZE 1000
# define START 1
# define END 2
# define COMMENT 4
# define ANTS 8
# define ROOM 16
# define TUBE 32
# define LOCKED 64
# define CURRENT 128
# define NEXT 256
# define USED 512

# include <string.h>

struct	s_rest
{
	int					fd;
	char				*rest;
	struct s_rest		*next;
};

struct	s_input
{
	char				*str;
	struct s_input		*next;
};

struct	s_room
{
	char				*name;
	int					x;
	int					y;
	int					status;
	int					lem;
	struct s_tube		*tube;
	struct s_room		*next;
};

struct	s_tube
{
	struct s_room		*link;
	struct s_tube		*next;
};

struct	s_way
{
	struct s_tube		*way;
	int					length;
	int					ants;
	struct s_way		*next;
};

typedef struct s_rest		t_rest;
typedef struct s_input		t_input;
typedef struct s_room		t_room;
typedef struct s_tube		t_tube;
typedef struct s_way		t_way;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_isspace(int c);
int		ft_isdigit(int c);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		get_next_line(const int fd, char **line);
int		ft_free_error(char *line, t_input *current);
int		ft_purchase(t_input **data, t_room **anthill);
int		ft_verif_room(t_room *tmp, t_room *anthill);
int		ft_comment(t_input **data, char *line, int *status);
t_input	*ft_create_data(t_input **data, char *line);
t_room	*ft_create_room(t_room **anthill, int status);
int		ft_read_ants(t_input **data, t_input **current, char *line,
		t_room **anthill);
int		ft_isroom(char *line);
int		ft_istube(char *line);
int		ft_read_room(t_input **current, char *line, t_room **tmp, int status);
int		ft_read_tube(t_input **current, char *line, t_room **anthill);
void	ft_create_tube(t_room *r1, t_room *r2);
t_way	*ft_find_way(t_room *anthill);
t_tube	*ft_create_link(t_room *ptr);
t_way	*ft_seek_shortest(t_room *anthill);
int		ft_search_end(t_way **list, t_way *end);
void	ft_print_anthill(t_room *anthill);
void	ft_print_way(t_way *ways);
void	ft_print_ants_way(t_way *ways);
void	ft_send_ants(int ants, t_way *ways);
void	ft_print_lem_move(int lem, char *name);
void	ft_print_send(t_way *ways);
void	ft_del_input(t_input *data);
void	ft_del_anthill(t_room *anthill);
void	ft_del_ways(t_way *ways);
void	ft_free_way(t_way *current);

#endif
