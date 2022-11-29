# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 11:50:05 by vicgarci          #+#    #+#              #
#    Updated: 2022/11/29 13:56:11 by vicgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Felix
LIBFT = libft_def/libftprintf.a
GLFW3 = glfw_build/src/libglfw3.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

FILES = open_window.c \
		main.c

OBJS = ${FILES:.c=.o}

all: libft glfw3 $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(GLFW3) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft_def
	$(MAKE) clean -C ./glfw_build

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(GLFW3)


re: fclean libft glfw3 $(NAME)

libft:
	$(MAKE) -C ./libft_def

glfw3:
	$(MAKE) -C ./glfw_build

norma:
	@echo 6966205b5b2024286e6f726d696e65747465207c206772657020274572726f7227207c207763202d6c29202d65712030205d5d3b207468656e206e6f726d696e657474653b20656c736520286e6f726d696e65747465207c206772657020274572726f7227293b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re libft norma