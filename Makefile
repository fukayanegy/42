# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 12:19:14 by etakaham          #+#    #+#              #
#    Updated: 2023/06/22 16:03:32 by etakaham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean