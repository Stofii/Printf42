# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstopfer <dstopfer@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 12:09:51 by dstopfer          #+#    #+#              #
#    Updated: 2022/05/24 23:16:27 by dstopfer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c functions.c cases.c conversions.c hexa.c\


OBJS = $(SRCS: .c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re