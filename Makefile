# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 12:19:14 by etakaham          #+#    #+#              #
#    Updated: 2023/06/17 14:16:25 by etakaham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean re clean
NAME	= gnl.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)

.c=.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
