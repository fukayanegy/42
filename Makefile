# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 12:19:14 by etakaham          #+#    #+#              #
#    Updated: 2023/06/23 21:10:30 by etakaham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
ADDFLAGS = -fsanitize=address -g
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

new: re clean

.PHONY: all fclean re clean
