# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 15:12:42 by mawelsch          #+#    #+#              #
#    Updated: 2025/11/12 01:46:17 by mawelsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

CFILES = push_swap.c parser.c ops.c simple_sort.c single_op_calls.c \
double_op_calls.c gulag_sort.c

OFILES = $(CFILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME) clean

$(NAME): $(OFILES)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME) -L./libft -l:libft.a

clean:
	rm -f $(OFILES) $(LIBFT_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all