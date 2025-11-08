# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 15:12:42 by mawelsch          #+#    #+#              #
#    Updated: 2025/11/08 18:30:07 by mawelsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

CFILES = main.c parser.c ops_ps.c ops_r.c ops_rr.c

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