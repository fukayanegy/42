# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 12:19:14 by etakaham          #+#    #+#              #
#    Updated: 2023/06/24 13:06:44 by etakaham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
ADDFLAGS = -fsanitize=address -g
SRCS	= get_next_line.c get_next_line_utils.c
HSRCS	= get_next_line.h
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

norm:
	norminette -R CheckForbiddenSorceHeader $(SRCS) $(HSRCS)

.PHONY: all fclean re clean
