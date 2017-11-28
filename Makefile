# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolivier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 14:06:26 by nolivier          #+#    #+#              #
#    Updated: 2017/05/19 11:22:29 by nolivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = ft_strlen.c \
	  ft_atoi.c \
	  ft_putchar.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_strcmp.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strchr.c \
	  ft_isspace.c \
	  ft_isdigit.c \
	  ft_strncpy.c \
	  get_next_line.c \
	  lemin.c \
	  ft_free_error.c \
	  ft_purchase.c \
	  ft_verif_room.c \
	  ft_comment.c \
	  ft_create_data.c \
	  ft_create_room.c \
	  ft_read_ants.c \
	  ft_isroom.c \
	  ft_istube.c \
	  ft_read_room.c \
	  ft_read_tube.c \
	  ft_create_tube.c \
	  ft_find_way.c \
	  ft_create_link.c \
	  ft_seek_shortest.c \
	  ft_search_end.c \
	  ft_print_anthill.c \
	  ft_print_way.c \
	  ft_print_ants_way.c \
	  ft_send_ants.c \
	  ft_print_lem_move.c \
	  ft_print_send.c \
	  ft_del_input.c \
	  ft_del_anthill.c \
	  ft_del_ways.c \
	  ft_free_way.c

OUT = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^

$(NAME): $(OUT)
	gcc -o $(NAME) $(OUT) $(FLAG)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
